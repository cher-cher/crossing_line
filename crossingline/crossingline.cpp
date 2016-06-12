#include "stdafx.h"
#include "crossingline.h"

using namespace std;

LineEquation CalculateCoefficients(const pair<double, double> & dot1, const pair<double, double> & dot2)
{
	return { dot1.second - dot2.second, dot2.first - dot1.first, dot1.first * dot2.second - dot2.first * dot1.second };
}

bool AreCrossing(const vector <pair<double, double>> &coordinates)
{
	double y = 0;
	double x = 0;
	LineEquation line1 = CalculateCoefficients(coordinates[0], coordinates[1]);
	LineEquation line2 = CalculateCoefficients(coordinates[2], coordinates[3]);
	if (coordinates[0] == coordinates[1] || coordinates[2] == coordinates[3])
	{
		cout << "Error! Wrong data!" << endl;
		return false;
	}
	if (line1.a * line2.b - line2.a * line1.b != 0)
	{
		x = -((line1.c * line2.b - line2.c * line1.b) / (line1.a * line2.b - line2.a * line1.b));
		y = -((line1.a * line2.c - line2.a * line1.c) / (line1.a * line2.b - line2.a * line1.b));
		cout << x << " " << y << endl;
		return true;
	}
	else
	{
		cout << "lines are parallel" << endl;
		return false;
	}
}