#include "CompilerBackend.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#include <llvm/IR/LLVMContext.h>
#include <llvm/PassRegistry.h>
#include <llvm/Support/Host.h>
#include <llvm/ADT/Triple.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Analysis/TargetLibraryInfo.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/MC/SubtargetFeature.h>
#pragma clang diagnostic pop

using namespace llvm;

namespace
{
	std::string getFeaturesStr()
	{
		SubtargetFeatures features;

		// We need to autodetect features.
		// This is necessary for x86 where the CPU might not support all the
		// features the autodetected CPU name lists in the target. For example,
		// not all Sandybridge processors support AVX.
		StringMap<bool> HostFeatures;
		if (sys::getHostCPUFeatures(HostFeatures))
		{
			for (auto &feature : HostFeatures)
			{
				if (feature.second)
				{
					features.AddFeature(feature.first());
				}
			}
		}

		return features.getString();
	}

	std::unique_ptr<tool_output_file> GetOutputStream(const std::string &outputPath)
	{
		// Open the file.
		std::error_code errorCode;
		sys::fs::OpenFlags flags = sys::fs::F_None;
		auto stream = llvm::make_unique<tool_output_file>(outputPath, errorCode, flags);
		if (errorCode)
		{
			throw std::runtime_error("Cannot create output file: " + errorCode.message());
		}

		return stream;
	}

	void InitializeBackend()
	{
		llvm::InitializeAllTargets();
		llvm::InitializeAllTargetMCs();
		llvm::InitializeAllAsmPrinters();
		llvm::InitializeAllAsmParsers();
	}

	PassRegistry *SetupPassRegistry()
	{
		PassRegistry *ret = PassRegistry::getPassRegistry();
		initializeCore(*ret);
		initializeCodeGen(*ret);
		initializeLoopStrengthReducePass(*ret);
		initializeLowerIntrinsicsPass(*ret);
		initializeUnreachableBlockElimPass(*ret);

		return ret;
	}

	const Target *TryGetTarget(const Triple &triple)
	{
		std::string error;
		const Target *target = TargetRegistry::lookupTarget(triple.getTriple(), error);
		if (!target)
		{
			throw std::runtime_error(error);
		}
		return target;
	}

	std::unique_ptr<TargetMachine> MakeTargetMachine(const Target *target, const Triple &triple, bool isDebug)
	{
		std::string cpuName = sys::getHostCPUName();
		std::string featuresStr = getFeaturesStr();
		CodeGenOpt::Level optLevel = isDebug ? CodeGenOpt::None : CodeGenOpt::Default;
		TargetOptions options;
		options.MCOptions.AsmVerbose = isDebug;

		return std::unique_ptr<TargetMachine>(target->createTargetMachine(triple.getTriple(), cpuName, featuresStr,
			options, Reloc::Default, CodeModel::Default, optLevel));
	}

}

CCompilerBackend::CCompilerBackend()
{
}

void CCompilerBackend::GenerateObjectFile(Module &module, bool isDebug, const std::string &outputPath)
{
	// �������������� ���������� LLVM ��� ��������� ����.
	InitializeBackend();
	SetupPassRegistry();

	// ���������� triple-������������ ������� ���������.
	// � ����� ������ ���������� ������� ��������� ������, �� ������� ������� ����������.
	Triple hostTriple(Triple::normalize(sys::getDefaultTargetTriple()));
	module.setTargetTriple(hostTriple.getTriple());
	const Target *target = TryGetTarget(hostTriple);
	std::unique_ptr<TargetMachine> targetMachine = MakeTargetMachine(target, hostTriple, isDebug);

	// ������ RAII-������ �����, ���� ����� ��������� �����.
	// ���� ����� ������������� ����� � �����������, ���� �� �� ������� ����� Keep().
	std::unique_ptr<tool_output_file> out = GetOutputStream(outputPath);

	std::string outputAssembly = outputPath + "_asm";
	std::unique_ptr<tool_output_file> outAsm = GetOutputStream(outputPath);

	// ������� ���� �������� ������������/��������������, ������� ����� ����������� � ������.
	legacy::PassManager passMananger;

	// ��������� ������ � ����������� �� triple-�������������� ������� ���������.
	TargetLibraryInfoImpl TLII(hostTriple);
	passMananger.add(new TargetLibraryInfoWrapperPass(TLII));

	// ������� � ������ IR-���� ������ ������� ���������.
	module.setDataLayout(targetMachine->createDataLayout());

	// ���������� ������� ��������� �������� ������� ��������������.
	if (targetMachine->addPassesToEmitFile(passMananger, out->os(), TargetMachine::CGFT_ObjectFile,
		false, nullptr, nullptr, nullptr, nullptr))
	{
		throw std::runtime_error("target does not support generation of this file type!");
	}

	// ��������� ������� �������� ������������/��������������.
	passMananger.run(module);

	// ���� ���������� ����� �� ���� �����, ��������� �������� ����.
	out->keep();

	
}
