
#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

vector<double> randuniform(int n); //生成均匀分布，返回vector
vector<double> randn(int n); ////生成标准正态分布，返回vector


int main()
{
    int n = 10;
    vector<double> vec{};
    vector<double> vecnormal{};

    vec = randuniform(n);
    for (auto val : vec)
        cout << val << " ";
    cout << endl;

    vecnormal = randn(n);
    for (auto val : vecnormal)
        cout << val << " ";
    cout << endl;


    return 0;
}

vector<double> randuniform(int n)
{
    vector<double> vec{};
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        vec.push_back((double) rand() / RAND_MAX);
    return vec;
}

vector<double> randn(int n)
{
    vector<double> vec(n, 0.0);
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    normal_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i < n; i++)
    {
        vec[i] = distribution(generator);
    }

    return vec;
}