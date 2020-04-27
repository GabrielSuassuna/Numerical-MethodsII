class Singularity {
public:
  Singularity();
  double simpleExponential(double inferior, double superior, double value,
                           double function(double));
  double simpleVariableChange(double inferior, double superior, double value);
  double simpleVariableChangeDerivative(double inferior, double superior,
                                        double value);
};