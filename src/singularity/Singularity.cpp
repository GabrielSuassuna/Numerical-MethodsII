#include "Singularity.hpp"
#include <math.h>

Singularity::Singularity(){};

long double Singularity::simpleVariableChange(long double inferior, long double superior,
                                              long double value)
{
       return ((inferior + superior) / 2.0) +
              ((superior - inferior) / 2.0) * tanh(value);
}

long double Singularity::simpleVariableChangeDerivative(long double inferior,
                                                        long double superior,
                                                        long double value)
{
       return ((superior - inferior) / 2.0) * (1.0 / pow(cosh(value), 2.0));
}

long double Singularity::simpleExponential(long double inferior, long double superior,
                                           long double value,
                                           long double (*function)(long double))
{
       return (function(simpleVariableChange(inferior, superior, value))) *
              simpleVariableChangeDerivative(inferior, superior, value);
}

long double Singularity::doubleVariableChange(long double inferior, long double superior,
                                              long double value)
{
       return ((inferior + superior) / 2.0) +
              ((superior - inferior) / 2.0) * tanh((M_PI / 2.0) * sinh(value));
}

long double Singularity::doubleVariableChangeDerivative(long double inferior,
                                                        long double superior,
                                                        long double value)
{

       return ((superior - inferior) / 2.0) * ((M_PI / 2.0) * (cosh(value) / pow(cosh((M_PI / 2.0) * sinh(value)), 2.0)));
}

long double Singularity::doubleExponential(long double inferior, long double superior,
                                           long double value,
                                           long double (*function)(long double))
{
       return (function(doubleVariableChange(inferior, superior, value))) *
              doubleVariableChangeDerivative(inferior, superior, value);
}