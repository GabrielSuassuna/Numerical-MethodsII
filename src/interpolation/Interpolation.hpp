#include <math.h>
#include <vector>
using namespace std;

class Interpolation
{
public:
    Interpolation(/* args */);
    int factorial(int x);
    double newtonBinomial(double s, double k);
    double newtonPolynomial();
    double deltaForward(int degree, double point, double deltaX, double function (double));
    double interpolationForward(int degree, double point, double deltaX, double pointNumber, double function (double));
};
