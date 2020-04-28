#include <iostream>
#include <math.h>
using namespace std;

class Singularity
{
public:
  Singularity();
  long double simpleExponential(long double inferior, long double superior, long double value,
                                long double function(long double));
  long double simpleVariableChange(long double inferior, long double superior, long double value);
  long double simpleVariableChangeDerivative(long double inferior, long double superior,
                                             long double value);
  long double doubleExponential(long double inferior, long double superior, long double value,
                                long double function(long double));
  long double doubleVariableChange(long double inferior, long double superior, long double value);
  long double doubleVariableChangeDerivative(long double inferior, long double superior,
                                             long double value);
};