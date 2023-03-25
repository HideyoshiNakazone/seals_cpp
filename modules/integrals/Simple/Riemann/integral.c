#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"

float f(float x)
{
    float y = pow(x,2);

    return y;
}

float riemann(float a, float b, float n)
{
    float delta = (b-a)/n, psi = a, theta = 0, integral;

    while ((psi+delta)<b)
    {
        theta = theta + ( f(psi) + f(psi+delta) )/2;
        psi += delta;
    }

    integral = delta*theta;

    return integral;
}