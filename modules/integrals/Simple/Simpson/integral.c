#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"
#include "global.h"

void line()
{
    printf("\n");
}

float f(float x)
{
    float y;

    y = exp(-(pow(x,2)));

    return y;
}

float x(float i)
{
    float delta = (b-a)/n;
    float x = a + i*delta;

    return x;
}

float simpson()
{
    float eta = 0;
    float theta = 0;
    float psi = 1;
    float kappa = 1;
    float delta = (b-a)/n;

    while (psi <= (n/2))
    {
        eta = eta + f(x(2*psi - 1));
        psi += 1;
    }
    while (kappa <= ((n/2)-1))
    {
        theta = theta + f(x(2*kappa));
        kappa = kappa + 1;
    }

    float integral = (delta/3)*( f(x(0)) + f(x(n)) + 4*eta + 2*theta);

    return integral;
}