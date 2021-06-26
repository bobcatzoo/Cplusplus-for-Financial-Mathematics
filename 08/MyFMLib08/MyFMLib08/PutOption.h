#pragma once
#include "BlackScholesModel.h"

class PutOption
{
public:
	double strike;
	double maturity;

public:
	double payoff(double stockAtMaturity) const;
	double price(BlackScholesModel& bsm) const;
};