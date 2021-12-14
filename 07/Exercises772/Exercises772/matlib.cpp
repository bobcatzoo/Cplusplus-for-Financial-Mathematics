
#include "stdafx.h"
#include "matlib.h"

const double PI = 3.141592653589793;

double mean_(const std::vector<double>& vec)
{
	double mean = 0.0;
	for (auto val : vec)
		mean += val;
	mean = mean / vec.size();
	return mean;
}

double standardVariation(const std::vector<double>& vec, std::string option)
{
	double stdvar = 0.0;
	double mean = mean_(vec);
	for (auto val : vec)
		stdvar += pow(val - mean, 2);
	
	if (option == "sample")
		return sqrt(stdvar / (vec.size() - 1));
	else
		return sqrt(stdvar / vec.size());
}

double max_(const std::vector<double>& vec)
{
	double max = 0.0;
	for (auto val : vec)
	{
		if (max <= val)
		{
			max = val;
		}
	}
	return max;
}

double min_(const std::vector<double>& vec)
{
	double min = 0.0;
	for (auto val : vec)
	{
		if (min >= val)
		{
			min = val;
		}
	}
	return min;
}

std::vector<double> randuniform(int n)
{
	std::vector<double> vec{};
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		vec.push_back((double)rand() / RAND_MAX);
	return vec;
}

std::vector<double> randn(int n)
{
	std::vector<double> vec(n, 0.0);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::normal_distribution<double> distribution(0.0, 1.0);
	for (int i = 0; i < n; i++)
	{
		vec[i] = distribution(generator);
	}

	return vec;
}

std::vector<double> BoxMuller(int n)
{
	std::vector<double> vecBM(n, 0.0);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{		
		double u1 = (double) rand() / RAND_MAX;
		double u2 = (double) rand() / RAND_MAX;
		double t = sqrt(-2 * log(u1)) * cos(2 * PI * u2);
		if (isinf(t) || isnan(t)) //Why?
		{
			i--;
			continue;
		}
		vecBM[i] = t;
		//std::cout << t << std::endl;
	}
	return vecBM;
}