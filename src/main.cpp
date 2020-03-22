#include <iostream> 
#include <math.h>
#include "derivative/Derivative.hpp"
#include "interpolation/Interpolation.hpp"
using namespace std;

double quadratic(double x) {
    return pow(x, 3) + x + 3;
}


int main(int argc, char const *argv[])
{
    //Derivative derivative = Derivative();
    Interpolation interpolation = Interpolation();
    cout << "Interpolation: " << interpolation.interpolationForward(2, 1.0, 0.00001, 1, quadratic) << endl;
    /*
    cout << "Forward: " << derivative.forward(2, 0.001, quadratic) << endl;
    cout << "Backward: " << derivative.backward(2, 0.001, quadratic) << endl;
    cout << "Centered: " << derivative.centered(2, 0.001, quadratic) << endl;
    */
    return 0;
}