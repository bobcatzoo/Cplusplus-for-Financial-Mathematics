// InterestCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int Principal; //投资本金
    double InterestRate; //年利率
    int NumberOfYears; //投资年数

    cout << "How much are you investing?" << endl;
    cin >> Principal;
    cout << "What's the annal interest rate (%)?" << endl;
    cin >> InterestRate;
    cout << "How long for (Years)?" << endl;
    cin >> NumberOfYears;

    double FinalBalance =
        pow(1.0 + InterestRate * 0.01, NumberOfYears) * Principal;
    // pow(a, b)表示a的b次方a^b
    double Interest = FinalBalance - Principal;

    cout << endl;
    cout << "The principal: " << Principal << endl;
    cout << "The annal interest rate: " << InterestRate << endl;
    cout << "Investment periods: " << NumberOfYears << endl;
    cout << endl;

    cout << "The final investment balance is " << FinalBalance << endl;
    cout << "You will earn " << Interest << endl;

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
