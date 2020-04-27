#include "NewtonCotesSingularity.hpp"
#include "../singularity/Singularity.hpp"

NewtonCotesSingularity::NewtonCotesSingularity(/* args */) {}

double NewtonCotesSingularity::openTrapezeRule(double inferior, double superior,
                                               double initialPoint,
                                               double finalPoint,
                                               double function(double)) {
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 3;
  double result = (deltaX / 2) *
                  (singularity.simpleExponential(inferior, superior,
                                                 initialPoint + h, function) +
                   singularity.simpleExponential(
                       inferior, superior, initialPoint + 2 * h, function));

  return result;
}

double NewtonCotesSingularity::milneRule(double inferior, double superior,
                                         double initialPoint, double finalPoint,
                                         double function(double)) {
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 4;
  double result =
      ((4 * h) / 3) *
      (2 * singularity.simpleExponential(inferior, superior, initialPoint + h,
                                         function) -
       singularity.simpleExponential(inferior, superior, initialPoint + 2 * h,
                                     function) +
       2 * singularity.simpleExponential(inferior, superior,
                                         initialPoint + 3 * h, function));

  return result;
}

double NewtonCotesSingularity::substituition3(double inferior, double superior,
                                              double initialPoint,
                                              double finalPoint,
                                              double function(double)) {
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 5;
  double result =
      ((5 * h) / 24) *
      (11 * singularity.simpleExponential(inferior, superior, initialPoint + h,
                                          function) +
       singularity.simpleExponential(inferior, superior, initialPoint + 2 * h,
                                     function) +
       singularity.simpleExponential(inferior, superior, initialPoint + 3 * h,
                                     function) +
       11 * singularity.simpleExponential(inferior, superior,
                                          initialPoint + 4 * h, function));

  return result;
}

double NewtonCotesSingularity::substituition4Open(double inferior,
                                                  double superior,
                                                  double initialPoint,
                                                  double finalPoint,
                                                  double function(double)) {
  Singularity singularity = Singularity();
  double deltaX = (finalPoint - initialPoint);
  double h = deltaX / 6;
  double result =
      ((3 * h) / 10) *
      (11 * singularity.simpleExponential(inferior, superior, initialPoint + h,
                                          function) -
       14 * singularity.simpleExponential(inferior, superior,
                                          initialPoint + 2 * h, function) +
       26 * singularity.simpleExponential(inferior, superior,
                                          initialPoint + 3 * h, function) -
       14 * singularity.simpleExponential(inferior, superior,
                                          initialPoint + 4 * h, function) +
       11 * singularity.simpleExponential(inferior, superior,
                                          initialPoint + 5 * h, function));

  return result;
}

vector<double> NewtonCotesSingularity::integralPartitions(
    double inferior, double superior, double initialPoint, double finalPoint,
    double epsilon, int degree, double function(double)) {
  double current_value = 0;
  double last_value;
  double part = 1;
  double deltaX;
  double sum;
  double xi;
  double xf;
  double iterations = 0;

  do {
    deltaX = (finalPoint - initialPoint) / part;
    sum = 0;

    for (int index = 0; index < part; index++) {
      xi = initialPoint + index * deltaX;
      xf = xi + deltaX;
      switch (degree) {
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