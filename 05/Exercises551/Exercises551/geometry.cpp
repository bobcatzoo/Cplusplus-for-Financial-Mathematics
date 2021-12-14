#include "geometry.h"
#include "stdafx.h"

double getCircleArea(double r)
{
	double area = 0.0;
	area = PI * pow(r, 2);

	return area;
}

double getCircleCircumference(double r)
{
	double circumference = 0.0;
	circumference = 2 * PI * r;

	return circumference;
}