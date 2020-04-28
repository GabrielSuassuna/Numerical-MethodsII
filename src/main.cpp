#include "newtonCotesSingularity/NewtonCotesSimple.hpp"
#include "newtonCotesSingularity/NewtonCotesDouble.hpp"
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

long double function1(long double x) { return 1.0 / pow(pow(x, 2), 1.0 / 3.0); }
long double function2(long double x) { return 1.0 / sqrt(4 - pow(x, 2)); }

int main(int argc, char const *argv[])
{
     NewtonCotesSimple functionsSimple = NewtonCotesSimple();
     NewtonCotesDouble functionsDouble = NewtonCotesDouble();
     vector<double> result = {};
     cout << "----------------------------------------" << endl;
     cout << "Exponencial simples" << endl;
     cout << endl
          << "Fórmula 1) " << endl;
     result = functionsSimple.integralPartitions(0, 1, -9, 9, 0.000001, 1, function1);
     cout << "Regra do Trapézio Aberta: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsSimple.integralPartitions(0, 1, -9, 9, 0.000001, 2, function1);
     cout << "Regra de Milne: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsSimple.integralPartitions(0, 1, -9, 9, 0.000001, 3, function1);
     cout << "Polinômio de substituição de grau 3: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsSimple.integralPartitions(0, 1, -9, 9, 0.000001, 4, function1);
     cout << "Polinômio de substituição de grau 4: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;

     cout << endl
          << "Fórmula 2) " << endl;
     result = functionsSimple.integralPartitions(-2, 0, -9, 9, 0.000001, 1, function2);
     cout << "Regra do Trapézio Aberta: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsSimple.integralPartitions(-2, 0, -9, 9, 0.000001, 2, function2);
     cout << "Regra de Milne: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsSimple.integralPartitions(-2, 0, -9, 9, 0.000001, 3, function2);
     cout << "Polinômio de substituição de grau 3: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsSimple.integralPartitions(-2, 0, -9, 9, 0.000001, 4, function2);
     cout << "Polinômio de substituição de grau 4: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;

     cout << "-------------------------------------" << endl;
     cout << "Exponencial dupla" << endl;
     cout << endl
          << "Fórmula 1) " << endl;
     result = functionsDouble.integralPartitions(0, 1, -3, 3, 0.000001, 1, function1);
     cout << "Regra do Trapézio Aberta: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsDouble.integralPartitions(0, 1, -3, 3, 0.000001, 2, function1);
     cout << "Regra de Milne: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsDouble.integralPartitions(0, 1, -3, 3, 0.000001, 3, function1);
     cout << "Polinômio de substituição de grau 3: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsDouble.integralPartitions(0, 1, -3, 3, 0.000001, 4, function1);
     cout << "Polinômio de substituição de grau 4: " << setprecision(10)
          << 2 * result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;

     cout << endl
          << "Fórmula 2) " << endl;
     result = functionsDouble.integralPartitions(-2, 0, -3, 3, 0.000001, 1, function2);
     cout << "Regra do Trapézio Aberta: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsDouble.integralPartitions(-2, 0, -3, 3, 0.000001, 2, function2);
     cout << "Regra de Milne: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsDouble.integralPartitions(-2, 0, -3, 3, 0.000001, 3, function2);
     cout << "Polinômio de substituição de grau 3: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     result = functionsDouble.integralPartitions(-2, 0, -3, 3, 0.000001, 4, function2);
     cout << "Polinômio de substituição de grau 4: " << setprecision(10)
          << result[0]
          << endl
          << "Iterações: "
          << result[1]
          << endl;
     return 0;
}