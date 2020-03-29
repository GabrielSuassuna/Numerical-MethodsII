#include <iostream>
#include <iomanip>
#include <math.h>
#include "newtonCotes/NewtonCotes.hpp"
using namespace std;

double function(double x)
{
    return pow((sin(2 * x) + 4 * pow(x, 2) + 3 * x), 2);
}

int main(int argc, char const *argv[])
{
    //Derivative derivative = Derivative();
    NewtonCotes functions = NewtonCotes();
    cout << "Fórmulas de Newton-Cotes Fechadas" << endl;
    cout << "Regra do Trapézio: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 1, false, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 1, false, function)[1]
         << endl;
    cout << "Regra de Simpson 1/3: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 2, false, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 2, false, function)[1]
         << endl;
    cout << "Regra de Simpson 3/8: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 3, false, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 3, false, function)[1]
         << endl;
    cout << "Polinômio de substituição de grau 4: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 4, false, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 4, false, function)[1]
         << endl
         << endl;

    cout << "Fórmulas de Newton-Cotes Abertas" << endl;
    cout << "Regra do Trapézio Aberta: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 1, true, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 1, true, function)[1]
         << endl;
    cout << "Regra de Milne: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 2, true, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 2, true, function)[1]
         << endl;
    cout << "Polinômio de substituição de grau 3: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 3, true, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 3, true, function)[1]
         << endl;
    cout << "Polinômio de substituição de grau 4: "
         << setprecision(10)
         << functions.integralPartitions(0, 1, 0.000001, 4, true, function)[0]
         << endl
         << "Iterações: "
         << functions.integralPartitions(0, 1, 0.000001, 4, true, function)[1]
         << endl;
    return 0;
}