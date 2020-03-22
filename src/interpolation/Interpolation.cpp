#include "Interpolation.hpp"
#include "../derivative/Derivative.hpp"
#include <iostream> 
using namespace std;

Interpolation::Interpolation()
{
}

double Interpolation::deltaForward(int degree, double point, double deltaX, double function (double))
{
    if (degree == 0){
        return function(point) ;
    }
    return deltaForward(degree-1, point + deltaX, deltaX, function) - deltaForward(degree-1, point, deltaX, function);
}

int Interpolation::factorial(int x)
{
    if (x == 0) {
        return 1;
    }
    int factor = x;
    while (factor > 1) {
        x *= factor - 1;
        factor--;
    }
    return x;
}

double Interpolation::newtonBinomial(double s, double n)
{
    double dividend = factorial(s);
    double divider = (factorial(n)*factorial(s-n));
    double result = dividend/divider;
    return result;
}

double Interpolation::interpolationForward(int degree, double point, double deltaX, double pointNumber, double function (double))
{
    double result = 0;
    for (int index = 1; index <= degree; index++) {
        result = result + (newtonBinomial(pointNumber, index) * deltaForward(index, point, deltaX, function));
    }
    result = result/deltaX;
    return result;
}
