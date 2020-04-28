#include "NewtonCotesSimple.hpp"
#include "../singularity/Singularity.hpp"

NewtonCotesSimple::NewtonCotesSimple(/* args */) {}

double NewtonCotesSimple::openTrapezeRule(double inferior, double superior,
                                          double initialPoint,
                                          double finalPoint,
                                          long double function(long double))
{
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 3.0;
  double result = (deltaX / 2.0) *
                  (singularity.simpleExponential(inferior, superior,
                                                 initialPoint + h, function) +
                   singularity.simpleExponential(
                       inferior, superior, initialPoint + 2.0 * h, function));

  return result;
}

double NewtonCotesSimple::milneRule(double inferior, double superior,
                                    double initialPoint, double finalPoint,
                                    long double function(long double))
{
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 4.0;
  double result =
      ((4.0 * h) / 3.0) *
      (2.0 * singularity.simpleExponential(inferior, superior, initialPoint + h,
                                           function) -
       singularity.simpleExponential(inferior, superior, initialPoint + 2.0 * h,
                                     function) +
       2.0 * singularity.simpleExponential(inferior, superior,
                                           initialPoint + 3.0 * h, function));

  return result;
}

double NewtonCotesSimple::substituition3(double inferior, double superior,
                                         double initialPoint,
                                         double finalPoint,
                                         long double function(long double))
{
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 5.0;
  double result =
      ((5.0 * h) / 24.0) *
      (11.0 * singularity.simpleExponential(inferior, superior, initialPoint + h,
                                            function) +
       singularity.simpleExponential(inferior, superior, initialPoint + 2.0 * h,
                                     function) +
       singularity.simpleExponential(inferior, superior, initialPoint + 3.0 * h,
                                     function) +
       11.0 * singularity.simpleExponential(inferior, superior,
                                            initialPoint + 4.0 * h, function));

  return result;
}

double NewtonCotesSimple::substituition4Open(double inferior,
                                             double superior,
                                             double initialPoint,
                                             double finalPoint,
                                             long double function(long double))
{
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 6.0;
  double result =
      ((3.0 * h) / 10.0) *
      (11.0 * singularity.simpleExponential(inferior, superior, initialPoint + h,
                                            function) -
       14.0 * singularity.simpleExponential(inferior, superior,
                                            initialPoint + 2.0 * h, function) +
       26.0 * singularity.simpleExponential(inferior, superior,
                                            initialPoint + 3.0 * h, function) -
       14.0 * singularity.simpleExponential(inferior, superior,
                                            initialPoint + 4.0 * h, function) +
       11.0 * singularity.simpleExponential(inferior, superior,
                                            initialPoint + 5.0 * h, function));

  return result;
}

vector<double> NewtonCotesSimple::integralPartitions(
    double inferior, double superior, double initialPoint, double finalPoint,
    double epsilon, int degree, long double function(long double))
{
  double current_value = 0;
  double last_value;
  double part = 1;
  double deltaX;
  double sum;
  double xi;
  double xf;
  double iterations = 0;

  do
  {
    deltaX = (finalPoint - initialPoint) / part;
    sum = 0;

    for (int index = 0; index < part; index++)
    {
      xi = initialPoint + index * deltaX;
      xf = xi + deltaX;
      switch (degree)
      {
      case 1:
        sum = sum + openTrapezeRule(inferior, superior, xi, xf, function);
        break;

      case 2:
        sum = sum + milneRule(inferior, superior, xi, xf, function);
        break;

      case 3:
        sum = sum + substituition3(inferior, superior, xi, xf, function);
        break;

      case 4:
        sum = sum + substituition4Open(inferior, superior, xi, xf, function);
        break;
      }
    }

    last_value = current_value;
    current_value = sum;
    part = 2 * part;
    iterations++;

  } while (abs((current_value - last_value) / current_value) > epsilon);

  return {current_value, iterations};
}