#include "stdafx.h"
#include "Quadratic.h"

void solveQuadratic(const double a, const double b, const double c, double& root1, double& root2)
{
	double rule = pow(b, 2) - 4 * a * c;
	if (rule < 0)
	{
		std::cout << "The Quadratic equation " << a << " * x^2 + " << b << " * x + " << c << " = 0" << " ";
		std::cout << "doesn't have roots" << std::endl;
	}
	else if (rule == 0)
	{
		root1 = root2 = (-b + sqrt(rule)) / (2 * a);
		std::cout << "The Quadratic equation " << a << " * x^2 + " << b << " * x + " << c << " = 0" << " ";
		std::cout << "have one root: " << root1 << std::endl;
	}
	else
	{
		root1 = (-b + sqrt(rule)) / (2 * a);
		root2 = (-b - sqrt(rule)) / (2 * a);
		std::cout << "The Quadratic equation " << a << " * x^2 + " << b << " * x + " << c << " = 0" << " ";
		std::cout << "have two roots." << std::endl;
		std::cout << "Root1 is: " << root1 << std::endl;
		std::cout << "Root2 is: " << root2 << std::endl;
	}
}

void solveQuadratic_Vector(const double a, const double b, const double c, std::vector<double> &v)
{
	double rule = pow(b, 2) - 4 * a * c;
	if (rule < 0)
	{
		std::cout << "The Quadratic equation " << a << " * x^2 + " << b << " * x + " << c << " = 0" << " ";
		std::cout << "doesn't have roots" << std::endl;
	}
	else if (rule == 0)
	{
		double root = (-b + sqrt(rule)) / (2 * a);
		v.push_back(root);
		std::cout << "The Quadratic equation " << a << " * x^2 + " << b << " * x + " << c << " = 0" << " ";
		std::cout << "have one root: ";
		for (auto i : v)
			std::cout << i << std::endl;
	}
	else
	{
		double root1 = (-b + sqrt(rule)) / (2 * a);
		double root2 = (-b - sqrt(rule)) / (2 * a);
		v.push_back(root1);
		v.push_back(root2);
		std::cout << "The Quadratic equation " << a << " * x^2 + " << b << " * x + " << c << " = 0" << " ";
		std::cout << "have two roots." << std::endl;
		std::cout << "Root1 is: " << v[0] << std::endl;
		std::cout << "Root2 is: " << v[1] << std::endl;
	}
}