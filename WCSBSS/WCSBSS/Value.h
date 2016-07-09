#pragma once

// TODO: remove it
struct SValue
{
	double value;
	static SValue create(double a) {
		return{ a };
	};
};

