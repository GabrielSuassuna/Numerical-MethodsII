#include "Singularity.hpp"
#include <math.h>

Singularity::Singularity(){};

double Singularity::simpleVariableChange(double inferior, double superior,
                                         double value) {
  return ((inferior + superior) / 2.0) +
         ((superior - inferior) / 2.0) * tanh(value);
}

double Singularity::simpleVariableChangeDerivative(double inferior,
                                                   double superior,
                                                   double value) {
  return ((superior - inferior) / 2.0) * (1.0 / pow(cosh(value), 2.0));
}

double Singularity::simpleExponential(double inferior, double superior,
                                      double value,
                                      double (*function)(double)) {
  return (function(simpleVariableChange(inferior, superior, value))) *
         simpleVariableChangeDerivative(inferior, superior, value);
}
