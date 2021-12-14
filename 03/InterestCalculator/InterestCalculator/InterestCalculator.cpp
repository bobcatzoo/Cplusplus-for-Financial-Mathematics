// InterestCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double compoundInterest(double P, double i, int n)
{
    double interest = P * pow(1 + i * 0.01, n) - P;
    return interest;
}

int main()
{
    double principal;
    double annalInterest;
    int numberOfYears;

    cout << "How much are you investing ?" << endl;
    cin >> principal;
    cout << "What's the annal interest rate (%) ?" << endl;
    cin >> annalInterest;
    cout << "How long for (Years) ?" << endl;
    cin >> numberOfYears;

    double interest = compoundInterest(principal, annalInterest, numberOfYears);
    cout << "You want to invest " << principal << " with annal interest rate of "
         << annalInterest << "% in " << numberOfYears << " Years." << endl;
    cout << "Finally you will earn " << interest << "." << endl;

    return 0;

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
