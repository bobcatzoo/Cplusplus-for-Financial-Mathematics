#include <iostream>
#include <vector>
#include "matlib.h"
using namespace std;

int main()
{
	vector<double> vec{ 1.0, 8.6, -2.5, 4.02, -9.1, 6.5, 10.5};
	double mean = 0.0;
	double stdPopVar = 0.0;
	double stdSampVar = 0.0;
	double max = 0.0;
	double min = 0.0;

	mean = mean_(vec);
	cout << "Vector mean: " << mean << endl;

	stdSampVar = standardVariation(vec);
	cout << "Vector sample std: " << stdSampVar << endl;

	stdPopVar = standardVariation(vec, "oops");
	cout << "Vector population std: " << stdPopVar << endl;

	max = max_(vec);
	cout << "Vector max value: " << max << endl;

	min = min_(vec);
	cout << "Vector min value: " << min << endl;

	//Exercises 7.7.5 and 7.7.6
	int n = 1000000;
	vector<double> vecuniform{};
	vector<double> vecnormal{};

	vecuniform = randuniform(n);
	cout << endl;
	/*
	for (auto val : vecuniform)
		cout << val << " ";
	cout << endl;
	*/
	cout << endl;
	vecnormal = randn(n);
	
	cout << endl;
	double meanUniform = mean_(vecuniform);
	double stdVarUniform = standardVariation(vecuniform);
	cout << "meanUniform: " << meanUniform << " " << "stdVarUniform: " << stdVarUniform << endl;

	double meanNorm = mean_(vecnormal);
	double stdVarNorm = standardVariation(vecnormal);
	cout << "meanNorm: " << meanNorm << " " << "stdVarNorm: " << stdVarNorm << endl;

	vector<double> vecBoxMuller;
	vecBoxMuller = BoxMuller(n);
	double meanBoxMuller = mean_(vecBoxMuller);
	double stdVarBoxMuller = standardVariation(vecBoxMuller);
	cout << "meanBoxMuller: " << meanBoxMuller << " " << "stdVarBoxMuller: " << stdVarBoxMuller << endl;

	return 0;
}
