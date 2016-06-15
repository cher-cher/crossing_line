// crossingline.cpp: определяет точку входа для консольного приложения.
//

/* 11.8. Пересечение отрезков (5)
Два отрезка на плоскости заданы целочисленными координатами своих концов в декартовой 
системе координат. Требуется определить, существует ли у них общая точка.*/

#include "stdafx.h"
#include "crossingline.h"

using namespace std;

int main(int argc, char * argv[])
{
	string fileName;
	string str;
	fileName = argv[1];
	ifstream fin;
	fin.open(fileName);

	vector <pair<double, double>> coordinates;
	double x;
	double y;

	if (fin)
	{
		while (fin >> x >> y)
		{
			coordinates.push_back(pair<double, double>(x, y));
		}
	}
	else
	{
		cout << "Error! File can't be open!" << endl;
	}

	if (AreCrossing(coordinates))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	return 0;
}
