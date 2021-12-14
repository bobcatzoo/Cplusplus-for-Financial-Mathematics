// Exercises398.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double normcdf(double x);
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
    cout << "The put option price is: " << put << endl; //0.183691
    cout << endl;
    
    cout << "Put-Call-Parity = call - put Testing" << endl;
    cout << "Call price - Put price is: " << call - put << endl;
    putCallParity = spotPrice - exp(-riskFreeRate * timeToMaturity) * strike;
    cout << "Put-Call-Parity is: " << putCallParity << endl;
    cout << "Wonderful!" << endl;

    return 0;
}


const double Pi = 3.141592653589793;
const double root2Pi = sqrt(2.0 * Pi);

double normcdf(double x)
{
    if (x < 0)
        return 1 - normcdf(-x);
    double k = 1 / (1 + 0.2316419 * x);
    double poly = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    double approx = 1.0 - 1.0 / root2Pi * exp(-0.5 * x * x) * poly;
    return approx;
}


double blackScholesCallPrice(double strikePrice, double maturity, double spotPrice,
                             double volatility, double riskFreeInterestRate)
{
    double d1 = 1 / (volatility * sqrt(maturity)) * (log(spotPrice / strikePrice) +
        (riskFreeInterestRate + 0.5 * volatility * volatility) * sqrt(maturity));
    double d2 = d1 - volatility * sqrt(maturity);

    double callPrice = normcdf(d1) * spotPrice - normcdf(d2) * strikePrice * exp(-riskFreeInterestRate * maturity);
    return callPrice;
}

double blackScholesPutPrice(double strikePrice, double maturity, double spotPrice,
    double volatility, double riskFreeInterestRate)
{
    double d1 = 1 / (volatility * sqrt(maturity)) * (log(spotPrice / strikePrice) +
        (riskFreeInterestRate + 0.5 * volatility * volatility) * sqrt(maturity));
    double d2 = d1 - volatility * sqrt(maturity);

    double putPrice = normcdf(-d2) * strikePrice * exp(-riskFreeInterestRate * maturity) - normcdf(-d1) * spotPrice;
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
