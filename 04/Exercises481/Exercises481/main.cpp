// Exercises481.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int factorial_while(int n);
int factorial_for(int n);
int factorial_doWhile(int n);

int main()
{
    int n;
    int fac_w = 1;
    int fac_f = 1;
    int fac_dw = 1;

    cout << "Enter a number: " << endl;
    cin >> n;
    fac_w = factorial_while(n);
    fac_f = factorial_for(n);
    fac_dw = factorial_doWhile(n);
    cout << "The factorial of " << n << " is: " << fac_w << endl;
    cout << "The factorial of " << n << " is: " << fac_f << endl;
    cout << "The factorial of " << n << " is: " << fac_dw << endl;

    return 0;
}

int factorial_while(int n)
{
    int fac = 1;
    while (n > 0)
    {
        fac *= n;
        n--;
    }
    return fac;
}

int factorial_for(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
    }
    return fac;
}
int factorial_doWhile(int n)
{
    int fac = 1;
    do
    {
        fac *= n;
        n--;
    } while (n > 0);
    return fac;
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
