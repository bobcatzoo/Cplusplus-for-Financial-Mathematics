#pragma once

const double PI = 3.1415926535897932384626433832795028842;

//class declaration
class CartesianPoint
{
public:
	double x;
	double y;

	double distanceTo(CartesianPoint p) const;
};

class PolarPoint
{
public:
	double r;
	double theta;
};

class Circle
{
public:
	double radius;
	double area() const;
	double circumference() const;
};

class Point
{
public:
	Point();
	double x;
	double y;
};


CartesianPoint polarToCartesion(const PolarPoint& p);

double perimeter(const CartesianPoint& p1, const CartesianPoint& p2, const CartesianPoint& p3);

