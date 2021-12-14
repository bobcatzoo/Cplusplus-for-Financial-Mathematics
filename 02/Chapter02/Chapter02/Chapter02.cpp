// Chapter02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int numberOfPlatonicSolids = 5;
    //int numberOfPlanets = 08;
    int numberOfPlanets = 8;

    cout << "numberOfPlatonicSolids: " << numberOfPlatonicSolids << endl;
    cout << "numberOfPlanets: " << numberOfPlanets << endl;
    cout << endl;

    //Test size_t
    size_t short_ = sizeof(short); //2
    cout << "A short takes up " << short_ << " byte(s)" << endl;

    size_t int_ = sizeof(int); //4
    cout << "A int takes up " << int_ << " byte(s)" << endl;

    size_t long_ = sizeof(long); //4
    cout << "A long takes up " << long_ << " byte(s)" << endl;

    size_t long_long_ = sizeof(long long); //8
    cout << "A long long takes up " << long_long_ << " byte(s)" << endl;

    size_t unsigned_short_ = sizeof(unsigned short); //
    cout << "A unsigned short takes up " << unsigned_short_ << " byte(s)" << endl;

    size_t unsigned_int_ = sizeof(unsigned int); //4
    cout << "A unsigned int takes up " << unsigned_int_ << " byte(s)" << endl;

    size_t unsigned_long_ = sizeof(unsigned long); //4
    cout << "A unsigned_long takes up " << unsigned_long_ << " byte(s)" << endl;

    size_t unsigned_long_long_ = sizeof(unsigned long long); //8
    cout << "A unsigned long long takes up " << unsigned_long_long_ << " byte(s)" << endl;
    cout << endl;

    //Test casting
    int anInt = 123;
    double aDouble = anInt;
    cout << "aDouble: " << aDouble << endl;

    double x = 123.6;
    double y = x;
    int z = (int)x; //conversion from ¡¯double¡¯ to ¡¯int¡¯, possible loss of data
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    int a = 5;
    double b = a;
    cout << "b: " << b << endl;

    double pi = 3.1415;
    double r = 4;
    double area = 0.5 * pi * r * r;
    cout << "Area of circle with ridus 4 is : " << area << endl;

    a = 3;
    b = 10;
    double c = a / b;
    //double c = ((double)a) / b;
    cout << "c: " << c << endl;

    pi = 3.141;
    int piRoundedDown_cstyle = (int)pi;
    cout << "piRoundedDown_cstyle: " << piRoundedDown_cstyle << endl;
    int piRoundedDown_cppstyle = static_cast<int>(pi);
    cout << "piRoundedDown_cppstyle: " << piRoundedDown_cppstyle << endl;
    cout << endl;

    double* dPointer = 0x00000000;
    cout << dPointer << endl;
    const char* speech = "To be or not to be?";
    cout << speech << endl;
    cout << endl;

    double x_ = 2.345;
    double y_ = sin(x_) + cos(1.234);
    cout << "The y is: " << y_ << endl;
    cout << "The 32nd power of 2 is " << pow(2, 32) << endl;
    cout << endl;

    int i = 3;
    int j = 0;
    j = (i += 4);
    cout << "The value of i is " << i << endl;
    cout << "The value of j is " << j << endl;

    i = 3;
    j = 0;
    j = 3 * (i += 4);
    cout << "The value of i is " << i << endl;
    cout << "The value of j is " << j << endl;
    cout << endl;

    int c_ = 5;
    c_++;
    cout << "5++: " << c_ << endl;

    int d = 5;
    int e = d++;
    cout << "d=: " << d << endl;
    cout << "e=d++: " << e << endl;
    int f = 5;
    int g = ++f;
    cout << "f=: " << f << endl;
    cout << "g=++f: " << g << endl;

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
