#pragma once

class Polynomial
{
public:
	std::vector<double> coefficients;
public:
	Polynomial();
	Polynomial(std::vector<double>& vec);
	explicit Polynomial(double c);
	double evaluate(double x);
	Polynomial add(Polynomial p);
};