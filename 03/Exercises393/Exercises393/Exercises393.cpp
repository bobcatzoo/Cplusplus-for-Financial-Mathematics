// Exercises393.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int fibonacci(int n);
void printFibonacci(int n);

int main()
{
    int N, fb_N;

    cout << "Enter fibonacci series index: " << endl;
    cin >> N;
    fb_N = fibonacci(N-1);
    cout << "The No." << N << " of fibonacci series is: " << fb_N << endl;
    cout << "The full fibonacci series is: ";
    cout << "0 1 ";
    printFibonacci(N-2);

    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacci(int n)
{
    static int n1 = 0, n2 = 1, n3;

    if (n > 0)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
        printFibonacci(n - 1);
    }
    
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
