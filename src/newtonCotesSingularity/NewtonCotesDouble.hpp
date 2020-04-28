#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class NewtonCotesDouble
{
public:
  NewtonCotesDouble(/* args */);
  double openTrapezeRule(double inferior, double superior, double initialPoint,
                         double finalPoint, long double function(long double));
  double milneRule(double inferior, double superior, double initialPoint,
                   double finalPoint, long double function(long double));
  double substituition3(double inferior, double superior, double initialPoint,
                        double finalPoint, long double function(long double));
  double substituition4Open(double inferior, double superior,
                            double initialPoint, double finalPoint,
                            long double function(long double));
  vector<double> integralPartitions(double inferior, double superior,
                                    double initialPoint, double finalPoint,
                                    double epsilon, int degree,
                                    long double function(long double));
};