#include "NewtonCotes.hpp"

NewtonCotes::NewtonCotes(/* args */)
{
}

double NewtonCotes::trapezeRule(double initialPoint,
                                double finalPoint,
                                double function(double))
{
    double deltaX = finalPoint - initialPoint;
    double result = (deltaX / 2) * (function(initialPoint) +
                                    function(initialPoint + deltaX));

    return result;
}

double NewtonCotes::openTrapezeRule(double initialPoint,
                                    double finalPoint,
                                    double function(double))
{
    double deltaX = (finalPoint - initialPoint);
    double h = deltaX / 3;
    double result = (deltaX / 2) * (function(initialPoint + h) +
                                    function(initialPoint + 2 * h));

    return result;
}

double NewtonCotes::simpsonFormula1_3(double initialPoint,
                                      double finalPoint,
                                      double function(double))
{
    double deltaX = (finalPoint - initialPoint);
    double h = deltaX / 2;
    double result = (h / 3) * (function(initialPoint) +
                               4 * function(initialPoint + h) +
                               function(finalPoint));
    return result;
}

double NewtonCotes::milneRule(double initialPoint,
                              double finalPoint,
                              double function(double))
{
    double deltaX = (finalPoint - initialPoint);
    double h = deltaX / 4;
    double result = ((4 * h) / 3) * (2 * function(initialPoint + h) -
                                     function(initialPoint + 2 * h) +
                                     2 * function(initialPoint + 3 * h));

    return result;
}

double NewtonCotes::simpsonFormula3_8(double initialPoint,
                                      double finalPoint,
                                      double function(double))
{
    double deltaX = (finalPoint - initialPoint);
    double h = deltaX / 3;

    double result = ((3 * h) / 8) * (function(initialPoint) +
                                     3 * function(initialPoint + h) +
                                     3 * function(initialPoint + 2 * h) +
                                     function(finalPoint));

    return result;
}

double NewtonCotes::substituition3(double initialPoint,
                                   double finalPoint,
                                   double function(double))
{
    double deltaX = (finalPoint - initialPoint);
    double h = deltaX / 5;
    double result = ((5 * h) / 24) * (11 * function(initialPoint + h) +
                                      function(initialPoint + 2 * h) +
                                      function(initialPoint + 3 * h) +
                                      11 * function(initialPoint + 4 * h));

    return result;
}

double NewtonCotes::substituition4Closed(double initialPoint,
                                         double finalPoint,
                                         double function(double))
{
    double deltaX = (finalPoint - initialPoint);
    double h = deltaX / 4;
    double result = ((2 * h) / 45) * (7 * function(initialPoint) +
                                      32 * function(initialPoint + h) +
                                      12 * function(initialPoint + 2 * h) +
                                      32 * function(initialPoint + 3 * h) +
                                      7 * function(finalPoint));

    return result;
}

double NewtonCotes::substituition4Open(double initialPoint,
                                       double finalPoint,
                                       double function(double))
{
    double deltaX = (finalPoint - initialPoint);
    double h = deltaX / 6;
    double result = ((3 * h) / 10) * (11 * function(initialPoint + h) -
                                      14 * function(initialPoint + 2 * h) +
                                      26 * function(initialPoint + 3 * h) -
                                      14 * function(initialPoint + 4 * h) +
                                      11 * function(initialPoint + 5 * h));

    return result;
}

vector<double> NewtonCotes::integralPartitions(double initialPoint,
                                               double finalPoint,
                                               double epsilon,
                                               int degree,
                                               bool open,
                                               double function(double))
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
            if (open)
            {
                switch (degree)
                {
                case 1:
                    sum = sum + openTrapezeRule(xi, xf, function);
                    break;

                case 2:
                    sum = sum + milneRule(xi, xf, function);
                    break;

                case 3:
                    sum = sum + substituition3(xi, xf, function);
                    break;

                case 4:
                    sum = sum + substituition4Open(xi, xf, function);
                    break;
                }
            }
            else
            {
                switch (degree)
                {
                case 1:
                    sum = sum + trapezeRule(xi, xf, function);
                    break;

                case 2:
                    sum = sum + simpsonFormula1_3(xi, xf, function);
                    break;

                case 3:
                    sum = sum + simpsonFormula3_8(xi, xf, function);
                    break;

                case 4:
                    sum = sum + substituition4Closed(xi, xf, function);
                    break;
                }
            }
        }

        last_value = current_value;
        current_value = sum;
        part = 2 * part;
        iterations++;

    } while (abs((current_value - last_value) / current_value) > epsilon);

    return {current_value, iterations};
}