// Exercises396.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <boost\math\distributions\normal.hpp>
#include <random>
using namespace std;

double normcdf(double x);
double hornerFunction(double x, double a0);
double hornerFunction(double x, double a0, double a1);
double hornerFunction(double x, double a0, double a1, double a2);
double hornerFunction(double x, double a0, double a1, double a2, double a3);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6);

int main()
{
    cout << "Manual normcdf Test" << endl;

    cout << "The probability of field x <=0: ";
    cout << normcdf(0) << endl;
    cout << "The probability of 1 sigma field: ";
    cout << normcdf(1) - normcdf(-1) << endl; //Probability of 1sigma field
    cout << "The probability of 2 sigma field: ";
    cout << normcdf(2) - normcdf(-2) << endl; //Probability of 2sigma field
    cout << "The probability of 3 sigma field: ";
    cout << normcdf(3) - normcdf(-3) << endl; //Probability of 3sigma field
    cout << endl;

    cout << "Boost Library normcdf Test" << endl;

    boost::math::normal_distribution<> norm(0, 1); //generate standard norm distribution
    cout << "The probability of field x <=0: ";
    cout << boost::math::cdf(norm, 0) << endl;
    cout << "The probability of 1 sigma field: ";
    cout << boost::math::cdf(norm, 1) - boost::math::cdf(norm, -1) << endl; //Probability of 1sigma field
    cout << "The probability of 2 sigma field: ";
    cout << boost::math::cdf(norm, 2) - boost::math::cdf(norm, -2) << endl; //Probability of 2sigma field
    cout << "The probability of 3 sigma field: ";
    cout << boost::math::cdf(norm, 3) - boost::math::cdf(norm, -3) << endl; //Probability of 3sigma field
    cout << endl;

    return 0;
}

const double Pi = 3.141592653589793;
const double root2Pi = sqrt(2.0 * Pi);

double normcdf(double x)
{
    if (x < 0)
        return 1 - normcdf(-x);
    double k = 1 / (1 + 0.2316419 * x);
    //double poly = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    double poly = hornerFunction(k, 0.0, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    double approx = 1.0 - 1.0 / root2Pi * exp(-0.5 * x * x) * poly;
    return approx;
}

double hornerFunction(double x, double a0)
{
    return a0;
}

double hornerFunction(double x, double a0, double a1)
{
    return a0 + x*hornerFunction(x, a1);
}

double hornerFunction(double x, double a0, double a1, double a2)
{
    return a0 + x*hornerFunction(x, a1, a2);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3)
{
    return a0 + x*hornerFunction(x, a1, a2, a3);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4)
{
    return a0 + x*hornerFunction(x, a1, a2, a3, a4);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5)
{
    return a0 + x*hornerFunction(x, a1, a2, a3, a4, a5);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
