// Exercises482.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double f_x(double x);
double integrate_fx(double a, double b, int n);
double integrate_sinx(double a, double b, int n);
const double PI = 3.141592653589793;

int main()
{
    double intSinX = 0.0;
    double intFX = 0.0;
    double a = 0.0;
    double b = PI;
    double c = 3.0;
    int n = 1000;
    
    cout << "Integrate sinx from " << a << " to " << b << endl;
    intSinX = integrate_sinx(a, b, n);
    cout << intSinX << endl;
    cout << endl;
    cout << "-cos(" << b << ")" << " + " << "cos(" << a << "):" << endl;
    cout << -(cos(b) - cos(a)) << endl;
    cout << endl;

    cout << "Integrate f_x = x from " << a << " to " << c << endl;
    intFX = integrate_fx(a, c, n);
    cout << intFX << endl;

    return 0;
}

double integrate_sinx(double a, double b, int n)
{
    double delta = (b - a) / n;
    double integrate = 0.0;
    for (int i = 0; i < n; i++)
    {
        double x = a + (i + 0.5) * delta;
        integrate += sin(x) * delta;
    }
    return integrate;
}

double f_x(double x)
{
    return x;
}

double integrate_fx(double a, double b, int n)
{
    double delta = (b - a) / n;
    double integrate = 0.0;
    int i = 0;
    while (i < n)
    {
        double x = a + (i + 0.5) * delta;
        integrate += f_x(x) * delta;
        i++;
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
