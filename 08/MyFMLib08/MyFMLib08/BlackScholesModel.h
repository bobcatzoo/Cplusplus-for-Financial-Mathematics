#pragma once

class BlackScholesModel
{
public:
	double stockPrice;
	double volatility;
	double reskFreeRate;
	double date;

public:
	BlackScholesModel();
	explicit BlackScholesModel(double stockPrice);
};

class CallOption
{
public:
	double strike;
	double maturity;
	CallOption(); //默认构造函数
	CallOption(double strike, double maturity);

public:
	double payoff(double stockAtMaturity) const;
	double price(BlackScholesModel& bsm) const;
};