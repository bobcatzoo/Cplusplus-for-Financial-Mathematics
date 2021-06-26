#include "stdafx.h"
#include "BlackScholesModel.h"
#include "matlib.h"
#include "PutOption.h"

double PutOption::payoff(double stockAtMaturity) const
{
	if (strike > stockAtMaturity)
		return strike - stockAtMaturity;
	else
		return 0.0;
}

double PutOption::price(BlackScholesModel& bsm) const
{
	double S = bsm.stockPrice;
	double K = strike;
	double sigma = bsm.volatility;
	double r = bsm.reskFreeRate;
	double T = maturity - bsm.date;

	double numerator = log(S / K) + (r + 0.5 * pow(sigma, 2) * T);
	double denominator = sigma * sqrt(T);
	double d1 = numerator / denominator;
	double d2 = d1 - denominator;

	return exp(-r * T) * K * normcdf(-d2) - S * normcdf(-d1);
}