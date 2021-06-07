// Exercise257.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int player1, player2; //初始化变量
    int diff; //初始化变量

    cout << "Type 0 for stone, ";
    cout << "1 for scissors, 2 for paper\n";
    cout << "Enter player 1’s move\n";
    cin >> player1;
    cout << "Enter player 2’s move\n";
    cin >> player2;
    
    //player1 == player2
    if (player1 == player2) {
        cout << "Its a draw\n";
    }
    else {
        diff = player1 - player2;
        if (diff == -2 || diff == 1) {
            cout << "Player 1 won\n";
        }
        else {
            cout << "Player 2 won\n";
        }
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
