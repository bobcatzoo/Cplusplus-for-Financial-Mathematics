// PositiveNegative.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void positiveNegative_break();
void positiveNegative_continue();
void countDown();
void printMessage(int score);
int max(int a, int b);

int main()
{
    //positiveNegative_break();
    //positiveNegative_continue();
    //countDown();
    /*
    while (true)
    {
        int score;
        cout << "Enter your luck number 1 ~ 9, Type Ctrl+C to quit." << endl;
        cin >> score;
        printMessage(score);
    }
    */
    //int max_;
    //max_ = max(1, 2);
    //cout << max_ << endl;

    for (int i = 0; i < 16; i++)
    {
        cout << i << "\n";
    }
    cout << endl;

    for (int  count = 0, power = 1; count < 10; count++, power *= 2)
    {
        cout << power << "\n";
    }

    return 0;
}

void positiveNegative_break()
{
    cout << "Enter positive number followed by a negative number to quit:" << endl;
    int total = 0;
    while (true)
    {
        int next;
        cin >> next;
        if (next < 0)
            break; // 跳出while循环
        total += next;
    }
    cout << "The total is " << total << endl;
 }

void positiveNegative_continue()
{
    cout << "Enter positive numbers, Type CTRL+C to quit." << endl;
    int total = 0;
    while (true)
    {
        int next;
        cin >> next;
        if (next < 0)
        {
            cout << "Enter a positive number:" << endl;
            continue; //忽略当前输入的next，继续执行cin >> next语句            
        }            
        total += next; //即时计算并输出截至当前的total值
        cout << "Positive total is " << total << endl;
    }
}

void countDown()
{
    int  i = 10;
    while (true)
    {
        if (i == 0) {
            return; // 返回到while执行前 This stops all looping and returns the execution to the point where the function was called.
        }
        cout << i << endl;
        i--;
    }
    cout << "Return" << endl;
}

// This program prints out the grade for an exam based on your mark. 
// Marks 0–4 are fails, 5 or 6 is a pass, 7 is a merit and 8 or 9 is a distinction.
void printMessage(int score) 
{
    switch (score)
    {
    case  0:
    case  1:
    case  2:
    case  3:
    case  4:
        cout << "You have failed.\n";
        break;
    case  5:
    case  6:
        cout << "You have passed.\n";
        break;
    case  7:
        cout << "Merit.\n";
        break;
    case  8:
    case  9:
        cout << "Distinction.\n";
        break;
    default:
        cout << "Invalid score.\n";
        break; // Always include a default case
    }
    cout << "Good luck in your future career." << endl;
}

int max(int a, int b)
{
    return  a > b ? a : b;
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
