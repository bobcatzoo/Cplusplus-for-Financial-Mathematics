
#include <iostream>
#include "stdafx.h"
#include "chart.h"
#include "optionChart.h"
#include "matlib.h"
using namespace std;

int main()
{
    string file("LineChart.html");
    vector<double> xvalues{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> yvalues{1, 4, 9, 16, 25, 36, 49, 64, 81};

    lineChart(file, xvalues, yvalues);

    //option call value against spot price
    string optionChartFile("OptionChart.html");

    double K = 100.0;
    double vol = 0.2;
    double r = 0.05;
    double T = 1.0;
    double S_t = 0.0; // spot price
    int N = 20;

    vector<double> spotPrices(N, 0.0);
    vector<double> callValues(N, 0.0);
    
    for (int i = 0; i < N; i++)
        spotPrices[i] = S_t + (double)10.0 * i;

    for (int i = 0; i < N; i++)
        callValues[i] = blackScholesCallPrice(K, T, spotPrices[i], vol, r);

    optionChart(optionChartFile, spotPrices, callValues);

    //double call = 0.0;
    //call = blackScholesCallPrice(K, T, 110, vol, r);
    //cout << "The call option price is: " << call << endl; //11.6725
    
    //Exercises 7.7.9
    vector<double> vec{ 1.0, 3.0, 4.0, 7.0 };
    double myptile = 0.0;
    double p = 32.5;
    int n = vec.size();
    myptile = myPrctile(vec, p);  
    cout << "myptile: " << myptile << endl;

    //int indexBelow = (int)(p * n / 100.0 - 0.5);
    //int indexAbove = indexBelow + 1;
    //cout << "indexBelow: " << indexBelow << endl;
    //cout << "indexAbove: " << indexAbove << endl;
    //double percentageBelow = 100.0 * (indexBelow + 0.5) / n;
    //double percentageAbove = 100.0 * (indexAbove + 0.5) / n;
    //cout << "percentageBelow: " << percentageBelow << endl;
    //cout << "percentageAbove: " << percentageAbove << endl;

    const vector<double> histVec{ 0.8, 1.0, 3.0, 3.0, 4.2, 5.1, 6.2, 5.1, 4.2, 8.2, 9.56, 12.6, 22.8, 16.8, 16.2, 6.2 };
    vector<int> countHist = vhist(histVec, 10);

    string histFile("histLineChart.html");

    histLineChart(histFile, histVec, 10);
        
    cout << endl;

    return 0;
}

