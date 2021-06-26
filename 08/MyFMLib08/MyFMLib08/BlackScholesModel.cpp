#include "stdafx.h"
#include "BlackScholesModel.h"
#include "matlib.h"

BlackScholesModel::BlackScholesModel() : stockPrice(0.0), volatility(0.0), reskFreeRate(0.0), date(0.0) {}

BlackScholesModel::BlackScholesModel(double S_t) : stockPrice(S_t) {}

CallOption::CallOption() : strike(0.0), maturity(0.0) {}

CallOption::CallOption(double S_t, double T) : strike(S_t), maturity(T) {}

double CallOption::payoff(double stockAtMaturity) const
{
	if (stockAtMaturity > strike)
		return stockAtMaturity - strike;
	else
		return 0.0;
}

double CallOption::price(BlackScholesModel& bsm) const
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

	return S * normcdf(d1) - exp(-r * T) * K * normcdf(d2);
}