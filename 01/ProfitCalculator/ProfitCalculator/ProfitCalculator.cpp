// ProfitCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double revenue;
	double cost;
    double grossProfit;
    double taxRate = 0.25;
    double tax;
    double netProfit;

    cout << "Please enter the revenue: " << endl;
    cin >> revenue;
    cout << "Please enter the cost: " << endl;
    cin >> cost;

    grossProfit = revenue - cost;
    if (grossProfit > 0)
    {
        tax = grossProfit * taxRate;
        netProfit = grossProfit - tax;
    }
    else
    {
        tax = 0;
        netProfit = grossProfit;
    }

    cout << endl;
    cout << "The gross profit is " << grossProfit << endl;
    cout << "The tax is " << tax << endl;
    cout << "The net profit is " << netProfit << endl;

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
