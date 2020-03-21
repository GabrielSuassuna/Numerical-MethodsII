#include <iostream> 
#include <math.h>
#include "derivative/Derivative.hpp"
#include "interpolation/Interpolation.hpp"
using namespace std;

double quadratic(double x) {
    return pow(x, 2) + x + 3;
}


int main(int argc, char const *argv[])
{
    Derivative derivative = Derivative();
    cout << "Forward: " << derivative.forward(2, 0.001, quadratic) << endl;
    cout << "Backward: " << derivative.backward(2, 0.001, quadratic) << endl;
    cout << "Centered: " << derivative.centered(2, 0.001, quadratic) << endl;

    Interpolation interpolation = Interpolation();
    cout << interpolation.newtonBinomial(2, 2) << endl;
    return 0;
}