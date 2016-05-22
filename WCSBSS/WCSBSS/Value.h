#pragma once
struct SValue
{
	double value;
	static SValue create(double a) {
		return{ a };
	};
};

