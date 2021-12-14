// Exercises483.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <boost\math\distributions\normal.hpp>
#include <random>
using namespace std;

double integrate_fx(double x);
const double PI = 3.141592653589793;

int main()
{
    double cdf_m = 0.0;
    double cdf_b = 0.0;
    double x = 1.0;

    cdf_m = integrate_fx(x);
    cout << cdf_m << endl;

    //用标准正态分布cdf检测积分函数是否正确
    boost::math::normal_distribution<> norm(0, 1); //generate standard norm distribution
    cdf_b = boost::math::cdf(norm, x); 
    cout << cdf_b << endl;
    cout << cdf_m * pow(2 * PI, -0.5) << endl; // 等于cdf_b

    return 0;
}


double integrate_fx(double x)
{
    int a = 0;
    int b = 1;
    double N = 1000;
    double delta = 1 / N;
    double integrate = 0.0;
    for (int i = 0; i < N; i++)
    {
        double s = a + (i + 0.5) * delta;
        double t = x + 1 - pow(s, -1);
        double f = pow(s, -2) * exp(-0.5 * t * t);
        integrate += f * delta;
    }
    return integrate;
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
