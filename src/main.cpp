#include "newtonCotesSingularity/NewtonCotesSingularity.hpp"
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

double function(double x) { return 1.0 / pow(pow(x, 2), 1.0 / 3.0); }

int main(int argc, char const *argv[]) {
  NewtonCotesSingularity functions = NewtonCotesSingularity();
  cout << "Fórmulas de Newton-Cotes Abertas" << endl;
  cout << "Regra do Trapézio Aberta: " << setprecision(10)
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 1, function)[0]
       << endl
       << "Iterações: "
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 1, function)[1]
       << endl;
  cout << "Regra de Milne: " << setprecision(10)
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 2, function)[0]
       << endl
       << "Iterações: "
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 2, function)[1]
       << endl;
  cout << "Polinômio de substituição de grau 3: " << setprecision(10)
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 3, function)[0]
       << endl
       << "Iterações: "
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 3, function)[1]
       << endl;
  cout << "Polinômio de substituição de grau 4: " << setprecision(10)
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 4, function)[0]
       << endl
       << "Iterações: "
       << functions.integralPartitions(-1, 1, -1, 1, 0.000001, 4, function)[1]
       << endl;
  return 0;
}