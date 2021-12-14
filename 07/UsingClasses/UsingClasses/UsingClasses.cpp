
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

double sum(const vector<double>& v);
void printNextValue1(int x);
void printNextValue2(int& x);
void polarToCartesian(double r, double theta, double& x, double& y);

int main()
{
    vector<double> myVector;

    myVector.push_back(12.0);
    myVector.push_back(13.0);
    myVector.push_back(14.0);

    cout << myVector[0] << endl;
    cout << myVector[1] << endl;
    cout << myVector[2] << endl;
    cout << endl;

    myVector[0] = 0.1;
    myVector[1] = 0.2;
    myVector[2] = 0.3;

    cout << myVector[0] << endl;
    cout << myVector[1] << endl;
    cout << myVector[2] << endl;
    cout << endl;

    int n = myVector.size();
    for (int i = 0; i < n; i++)
    {
        cout << myVector[i] << " ";
    }
    cout << endl;

    vector<double> ten3s (10, 3.0);
    for (auto i : ten3s)
    {
        cout << i << " ";
    }
    cout << endl;

    vector <double> copy(ten3s);
    for (auto i : copy)
    {
        cout << i << " ";
    }
    cout << endl;

    copy = myVector;
    for (auto i : copy)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> threeInts({ 1, 2, 3 });
    for (auto i : threeInts)
    {
        cout << i << " ";
    }
    cout << endl;

    double sumMyVector = sum(myVector);
    cout << "Sum of myVector : " << sumMyVector << endl;

    int x = 10;
    cout << "A: Value of x is " << x << endl;
    printNextValue1(x);
    cout << "C: Value of x is " << x << endl;
    cout << endl;
    cout << "A: Value of x is " << x << endl;
    printNextValue2(x);
    cout << "C: Value of x is " << x << endl;

    double r = 2.0;
    double theta = PI / 2;
    double x_ = 0.0;
    double y = 0.0;

    cout << endl;
    polarToCartesian(r, theta, x_, y);
    cout << x_ << "\t" << y << endl;

    //Test fstream
    ofstream out;
    out.open("myFile.txt");
    out << "This is the first line" << endl;
    out << "This is the second line" << endl;
    out << "This is the third line" << endl;
    out.close();

    return 0;
}

double sum(const vector<double>& v)
{
    double sum = 0.0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    return sum;
}

void printNextValue1(int x)
{
    x = x + 1;
    cout << "B: value of x is " << x << endl;
}
void printNextValue2(int& x)
{
    x = x + 1;
    cout << "B: value of x is " << x << endl;
}

void polarToCartesian(double r, double theta, double& x, double& y)
{
    x = r * cos(theta);
    y = r * sin(theta);
}