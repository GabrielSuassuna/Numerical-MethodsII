#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

class NewtonCotes
{
public:
    NewtonCotes(/* args */);
    double trapezeRule(double initialPoint,
                       double finalPoint,
                       double function(double));
    double openTrapezeRule(double initialPoint,
                           double finalPoint,
                           double function(double));
    double simpsonFormula1_3(double initialPoint,
                             double finalPoint,
                             double function(double));
    double milneRule(double initialPoint,
                     double finalPoint,
                     double function(double));
    double simpsonFormula3_8(double initialPoint,
                             double finalPoint,
                             double function(double));
    double substituition3(double initialPoint,
                          double finalPoint,
                          double function(double));
    double substituition4Closed(double initialPoint,
                                double finalPoint,
                                double function(double));
    double substituition4Open(double initialPoint,
                              double finalPoint,
                              double function(double));
    vector<double> integralPartitions(double initialPoint,
                                      double finalPoint,
                                      double epsilon,
                                      int degree,
                                      bool open,
                                      double function(double));
};