class Derivative
{
public:
    Derivative();
    double forward(double x, double deltaX, double function (double));
    double backward(double x, double deltaX, double function (double));
    double centered(double x, double deltaX, double function (double));
};