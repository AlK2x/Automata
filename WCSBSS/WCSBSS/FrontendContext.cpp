#include "NodeAST.h"
#include "FrontendContext.h"
#include "StringPool.h"
#include "stdafx.h"


CFrontendContext::CFrontendContext(std::ostream &errors, CStringPool &pool)
	: m_pool(pool)
	, m_errors(errors)
{
}

CFrontendContext::~CFrontendContext()
{
}

std::string CFrontendContext::GetString(unsigned stringId) const
{
	return m_pool.GetString(stringId);
}

void CFrontendContext::PrintError(const std::string &message)const
{
	++m_errorsCount;
	m_errors << "  Error: " << message << std::endl;
}

unsigned CFrontendContext::GetErrorsCount() const
{
	return m_errorsCount;
}
