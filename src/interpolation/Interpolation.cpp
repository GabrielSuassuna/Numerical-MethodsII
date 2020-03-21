#include "Interpolation.hpp"

Interpolation::Interpolation(/* args */)
{
}

Interpolation::~Interpolation()
{
}

double Interpolation::deltaFunction(int degree, vector<double> pointArray, double function (double))
{
    if (degree == 0){
        return function()
    }
    double delta = deltaFunction(degree-1, point+1) - deltaFunction(degree-1, point)
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

double Interpolation::newtonBinomial(double s, double k)
{
    int dividend = factorial(s);
    int divider = (factorial(k)*factorial(s-k));
    double result = dividend/divider;
    return result;
}