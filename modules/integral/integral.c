#include "integral.h"


double _x(double a, double b, int n, int i) {
    float delta = (b-a)/n;
    float x = a + i*delta;

    return x;
}

double riemman_simple(double (*f)(double), double a, double b, int n) {
    double delta = (b-a)/n;

    double sum = 0;
    for (int i = a; i < (b-delta); i+=delta) {
        sum = sum + ( f(i) + f(i+delta) )/2;
    }

    return delta*sum;
}

double simpson_simple(double (*f)(double), double a, double b, int n) {
    double delta = (b-a)/n;


    double eta = 0;
    double theta = 0;
    double psi = 1;
    double kappa = 1;

    for (int psi = 0; psi <= (n/2); psi++) {
        eta = eta + f(_x(a, b, n, 2*psi - 1));
    }
    for (int kappa = 0; kappa <= ((n/2)-1); kappa++) {
        theta = theta + f(_x(a, b, n, 2*kappa));
    }

    return (delta/3)*( f(_x(a, b, n, 0)) + f(_x(a, b, n, n)) + 4*eta + 2*theta);
}

double riemann_double(double (*f)(double, double), double a, double b, double c, double d, int n) {
    double dx = (b-a)/n;
    double dy = (d-c)/n;
    double kappa = a;
    double psi = c;
    double theta = 0;

    for (int psi = c; (psi < (d - dy)); psi += dy) {
        for (int kappa = a; (kappa < (b - dx)); kappa += dx) {
            theta = theta + f(kappa, psi);
        }
    }

    return theta*(dx)*(dy);
}