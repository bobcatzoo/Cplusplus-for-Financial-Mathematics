// Exercises484.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
    int fib_N;
    int fib = 0;

    cout << "Enter a number:" << endl;
    cin >> fib_N;
    fib = fibonacci(fib_N);
    cout << "The " << fib_N << " th number of Fibonacci is " << fib << endl;

    return 0;
}

int fibonacci(int n)
{
    int fib = 0;
    if (n == 1 || n == 2)
        fib = 1;
    
    int n1 = 1;
    int n2 = 1;
    for (int i = 2; i < n; i++)
    {
        int n3 = n1 + n2;
        fib = n3;
        n1 = n2;
        n2 = n3;
    }
    
    return fib;

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
