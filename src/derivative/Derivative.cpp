#include "Derivative.hpp"

Derivative::Derivative()
{
}

double Derivative::forward(double x, double deltaX, double function (double)){
    return (function(x+deltaX)-function(x))/deltaX;
}

double Derivative::backward(double x, double deltaX, double function (double)){
    return (function(x)-function(x-deltaX))/deltaX;
}

double Derivative::centered(double x, double deltaX, double function (double)){
    return (function(x+deltaX)-function(x-deltaX))/(2*deltaX);
}

Derivative::~Derivative()
{
}
