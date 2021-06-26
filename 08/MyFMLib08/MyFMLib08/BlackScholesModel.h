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
	CallOption(); //Ĭ�Ϲ��캯��
	CallOption(double strike, double maturity);

public:
	double payoff(double stockAtMaturity) const;
	double price(BlackScholesModel& bsm) const;
};