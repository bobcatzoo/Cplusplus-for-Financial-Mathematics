#include "stdafx.h"
#include "Polynomial.h"

Polynomial::Polynomial()
{
	coefficients.push_back(0.0);
}

Polynomial::Polynomial(std::vector<double>& vec)
{
	for (auto val : vec)
		coefficients.push_back(val);
}

Polynomial::Polynomial(double c)
{
	coefficients.push_back(c);
}

double Polynomial::evaluate(double x)
{
	double value = 0.0;
	for (int i = 0; i < coefficients.size(); i++)
		value += coefficients[i] * pow(x, i);
	return value;
}

Polynomial Polynomial::add(Polynomial p)
{
	if (coefficients.size() <= p.coefficients.size())
	{
		for (int i = 0; i < coefficients.size(); i++)
			p.coefficients[i] += coefficients[i];
		return Polynomial(p.coefficients);
	}
	else
	{
		for (int i = 0; i < p.coefficients.size(); i++)
			coefficients[i] += p.coefficients[i];
		return Polynomial(coefficients);
	}
}