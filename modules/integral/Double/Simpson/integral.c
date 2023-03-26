#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"
#include "global.h"

double f(double x, double y)
{
    return pow(x,2) + x*y;
}

void line()
{
    printf("\n");
}

double x(int i)
{
    double x = a + i*dx;

    return x;
}

double y(int j)
{
    double y = c + j*dy;

    return y;
}

double g(int i)
{
    double sigma = 0;
    double upsilon  = 0;

    int zeta = 1;
    int csi = 1;

    while (zeta <= (m/2))
    {
        sigma += f(x(i),y(2*zeta - 1));
        zeta += 1;
    }
    while (csi <= ((m/2)-1))
    {
        upsilon  += f(x(i),y(2*csi));
        csi += 1;
    }
    double g = (dy/3)*( f(x(i),y(0)) + f(x(i),y(m)) + 4*sigma + 2*upsilon );

    return g;
}
double simpson()
{
    double eta = 0;
    double theta = 0;

    int psi = 1;
    int kappa = 1;

    while (psi < (n/2))
    {
        eta += g(2*psi - 1);
        psi += 1;
    }
    while (kappa < ((n/2)-1))
    {
        theta += g(2*kappa);
        kappa += 1;
    }

    double integral = (dx/3)*( g(0) + g(n) + 4*eta + 2*theta);

    return integral;
}
