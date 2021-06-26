
#include "stdafx.h"
#include "geometry.h"

CartesianPoint polarToCartesion(const PolarPoint& p)
{
	CartesianPoint c;
	c.x = p.r * cos(p.theta);
	c.y = p.r * sin(p.theta);

	return c;
}

double CartesianPoint::distanceTo(CartesianPoint p) const
{
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

double Circle::area() const
{
	return PI * pow(radius, 2);
}

double Circle::circumference() const
{
	return 2 * PI * radius;
}

double perimeter(const CartesianPoint& p1, const CartesianPoint& p2, const CartesianPoint& p3)
{
	double perimeter_ = 0.0;
	perimeter_ += p1.distanceTo(p2);
	perimeter_ += p1.distanceTo(p3);
	perimeter_ += p2.distanceTo(p3);

	return perimeter_;
}

/*
Point::Point()
{
	x = 0.0;
	y = 0.0;
}
*/

Point::Point() : x(0.0), y(0.0) {}
