#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class NewtonCotesSingularity {
public:
  NewtonCotesSingularity(/* args */);
  double openTrapezeRule(double inferior, double superior, double initialPoint,
                         double finalPoint, double function(double));
  double milneRule(double inferior, double superior, double initialPoint,
                   double finalPoint, double function(double));
  double substituition3(double inferior, double superior, double initialPoint,
                        double finalPoint, double function(double));
  double substituition4Open(double inferior, double superior,
                            double initialPoint, double finalPoint,
                            double function(double));
  vector<double> integralPartitions(double inferior, double superior,
                                    double initialPoint, double finalPoint,
                                    double epsilon, int degree,
                                    double function(double));
};