
#include <iostream>
#include <vector>
#include "Quadratic.h"
using namespace std;

int main()
{
    double a = 2.0, b = 4, c = 1.5;
    double root1 = 0.0, root2 = 0.0;
    vector<double> roots;

    
    solveQuadratic(a, b, c, root1, root2);
    //cout << root1 << " " << root2 << endl;
    cout << endl;
    solveQuadratic_Vector(a, b, c, roots);
    for (auto val : roots)
        cout << val << endl;

    return 0;
}
