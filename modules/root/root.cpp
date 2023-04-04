#include "root.h"


double bissec(double (*f)(double), double a, double b, double eps) {
    double fa = f(a);
    double fb = f(b);

    double c, fc;
    do {
        c = (a + b) / 2;
        fc = f(c);
        if (fa * fc <= 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    } while (fabs(b - a) > eps);

    c = (a + b) / 2;
    return c;
}

double newton(double (*f)(double), double (*df)(double), double x0, double eps) {
    double x = x0;
    do {
        x0 = x;
        x = x0 - (f(x0) / df(x0));
    }
    while (fabs(x-x0) > eps);

    return x;
}

double mist(double (*f)(double), double (*df)(double), double a, double b, double eps) {
    double c = bissec(f, a, b, 0.1);
    
    return newton(f, df, c, eps);
}