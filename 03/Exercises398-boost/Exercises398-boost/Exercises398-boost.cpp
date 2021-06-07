// Exercises398-boost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// using boost library's normcdf ~ boost::math::cdf(norm, x)

#include <iostream>
#include <cmath>
#include <boost\math\distributions\normal.hpp>
#include <random>
using namespace std;

double blackScholesCallPrice(double strikePrice, double maturity, double spotPrice,
    double volatility, double riskFreeInterestRate);
double blackScholesPutPrice(double strikePrice, double maturity, double spotPrice,
    double volatility, double riskFreeInterestRate);

int main()
{
    double strike = 100.0;
    double spotPrice = 110.0;
    double vol = 0.1;
    double riskFreeRate = 0.03;
    double timeToMaturity = 0.5;
    double call;
    double put;
    double putCallParity;

    call = blackScholesCallPrice(strike, timeToMaturity, spotPrice, vol, riskFreeRate);
    cout << "The call option price is: " << call << endl; //11.6725
    put = blackScholesPutPrice(strike, timeToMaturity, spotPrice, vol, riskFreeRate);
    cout << "The put option price is: " << put << endl; //0.183688
    cout << endl;

    cout << "Put-Call-Parity = call - put Testing" << endl;
    cout << "Call price - Put price is: " << call - put << endl;
    putCallParity = spotPrice - exp(-riskFreeRate * timeToMaturity) * strike;
    cout << "Put-Call-Parity is: " << putCallParity << endl;
    cout << "Wonderful!, It's correct." << endl;

    return 0;
}

double blackScholesCallPrice(double strikePrice, double maturity, double spotPrice,
    double volatility, double riskFreeInterestRate)
{
    double d1 = 1 / (volatility * sqrt(maturity)) * (log(spotPrice / strikePrice) +
        (riskFreeInterestRate + 0.5 * volatility * volatility) * sqrt(maturity));
    double d2 = d1 - volatility * sqrt(maturity);

    boost::math::normal_distribution<> norm(0, 1); //generate standard norm distribution
    double callPrice = boost::math::cdf(norm, d1) * spotPrice - boost::math::cdf(norm, d2) * strikePrice * exp(-riskFreeInterestRate * maturity);
    return callPrice;
}

double blackScholesPutPrice(double strikePrice, double maturity, double spotPrice,
    double volatility, double riskFreeInterestRate)
{
    double d1 = 1 / (volatility * sqrt(maturity)) * (log(spotPrice / strikePrice) +
        (riskFreeInterestRate + 0.5 * volatility * volatility) * sqrt(maturity));
    double d2 = d1 - volatility * sqrt(maturity);

    boost::math::normal_distribution<> norm(0, 1); //generate standard norm distribution
    double putPrice = boost::math::cdf(norm, -d2) * strikePrice * exp(-riskFreeInterestRate * maturity)
        - boost::math::cdf(norm, -d1) * spotPrice;
    return putPrice;
}
// Put-Call-Parity formula
// spotPrice - exp(-riskFreeInterestRate * maturity) * strikePrice = callPrice - putPrice

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
