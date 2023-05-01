#include "integral.h"


double _partition(double a, double delta, int i) {
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
    for (int psi = 1; psi <= (n/2); psi++) {
        eta = eta + f(_partition(a, delta, 2*psi - 1));
    }

    double theta = 0;
    for (int kappa = 1; kappa <= ((n/2)-1); kappa++) {
        theta = theta + f(_partition(a, delta, 2*kappa));
    }

    return (delta/3)*( f(_partition(a, delta, 0)) + f(_partition(a, delta, n)) + 4*eta + 2*theta);
}

double riemann_double(double (*f)(double, double), double a, double b, double c, double d, int n) {
    double dx = (b-a)/n;
    double dy = (d-c)/n;

    double theta = 0;
    for (double psi = c; psi <= d; psi += dy) {
        for (double kappa = a; kappa <= b; kappa += dx) {
            theta += f(kappa, psi);
        }
    }

    return theta*(dx)*(dy);
}

double _g(double (*f)(double, double), double a, double b, double c, double d, int n, int i) {
    double dx = (b-a)/n;
    double dy = (d-c)/n;

    double sigma = 0;
    for(int zeta = 1; zeta <= (n/2); zeta++) {
        sigma += f(_partition(a, dx, i),_partition(c, dy, 2*zeta - 1));
    }

    double upsilon  = 0;
    for (int csi = 1; csi <= ((n/2)-1); csi++) {
        upsilon  += f(_partition(a, dx, i),_partition(c, dy, 2*csi));
    }

    return (dy/3)*( f(_partition(a, dx, i),_partition(c, dy, 0)) + f(_partition(a, dx, i),_partition(c, dy, n)) + 4*sigma + 2*upsilon );
}

double simpson_double(double (*f)(double, double), double a, double b, double c, double d, int n) {
    double dx = (b-a)/n;

    double eta = 0;
    for (int psi = 1; psi < (n/2); psi++) {
        eta += _g(f, a, b, c, d, n, 2*psi - 1);
    }

    double theta = 0;
    for (int kappa = 1; kappa < ((n/2)-1); kappa++) {
        theta += _g(f, a, b, c, d, n, 2*kappa);
    }

    return (dx/3)*( _g(f, a, b, c, d, n, 0) + _g(f, a, b, c, d, n, n) + 4*eta + 2*theta);
}
