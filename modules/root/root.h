#include <math.h>


double bissec(double (*f)(double), double a, double b, double eps);

double newton(double (*f)(double), double (*df)(double), double x0, double eps);

double mist(double (*f)(double), double (*df)(double), double a, double b, double eps);