// crossinglinetest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../crossingline/crossingline.h"

using namespace std;

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	BOOST_CHECK_EQUAL(2 * 2, 4);
}

BOOST_AUTO_TEST_SUITE(crossing_line_test)

	BOOST_AUTO_TEST_CASE(lines_are_cross)
	{
		vector <pair<double, double>> coordinates = { { 10, 10 }, { 7, 3 }, { 1, 9 }, { 15, 4 } };
		BOOST_CHECK_EQUAL(AreCrossing(coordinates), true);

		vector <pair<double, double>> coordinates1 = { { 10, 7 }, { 10, 3 }, { 1, 9 }, { 15, 4 } };
		BOOST_CHECK_EQUAL(AreCrossing(coordinates1), true);

		vector <pair<double, double>> coordinates2 = { { 1, 1 }, { 4, 4 }, { 1, 3 }, { 3, 1 } };
		BOOST_CHECK_EQUAL(AreCrossing(coordinates2), true);
	}

	BOOST_AUTO_TEST_CASE(lines_are_perpendicular_and_intersect)
	{
		vector <pair<double, double>> coordinates = { { 2, 1 }, { 2, 3 }, { 1, 2 }, { 3, 2 } };
		BOOST_CHECK_EQUAL(AreCrossing(coordinates), true);
	}

	BOOST_AUTO_TEST_CASE(one_of_lines_is_dot)
	{
		vector <pair<double, double>> coordinates = { { 0, 0 },{ 0, 0 },{ 1, 2 },{ 3, 2 } };
		BOOST_CHECK_EQUAL(AreCrossing(coordinates), false);
	}

	BOOST_AUTO_TEST_CASE(lines_are_parallel)
	{
		vector <pair<double, double>> coordinates = { { 1, 1 },{ 1, 3 },{ 3, 1 },{ 3, 3 } };
		BOOST_CHECK_EQUAL(AreCrossing(coordinates), false);
	}

	BOOST_AUTO_TEST_CASE(lines_have_common_coordinate)
	{
		vector <pair<double, double>> coordinates = { { 1, 1 },{ 1, 3 },{ 1, 1 },{ 3, 1 } };
		BOOST_CHECK_EQUAL(AreCrossing(coordinates), true);
	}

BOOST_AUTO_TEST_SUITE_END()