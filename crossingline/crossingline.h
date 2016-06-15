#pragma once
#include "stdafx.h"

struct LineEquation
{
	double a = 0;
	double b = 0;
	double c = 0;
	LineEquation(double k, double m, double b)
		: a(k)
		, b(m)
		, c(b)
	{}
};

LineEquation CalculateCoefficients(const std::pair<double, double> & dot1, const std::pair<double, double> & dot2);
bool AreCrossing(const std::vector <std::pair<double, double>> &coordinates);