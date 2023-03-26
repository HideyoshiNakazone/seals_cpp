#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"
#include "global.h"

float f(float x, float y)
{
    float z = pow(x,2) + pow(y,2);

    return z;
}

void line()
{
    printf("\n");
}

float riemann()
{
    float dx = (b-a)/n;
    float dy = (d-c)/m;
    float kappa = a;
    float psi = c;
    float theta = 0;

    while ((psi + dy) < d)
    {
        while ((kappa + dx) < b)
        {
            theta = theta + f(kappa, psi);
            kappa = kappa + dx;
        }
        psi = psi + dy;
        kappa = a;
    }

    float integral = theta*(dx)*(dy);

    return integral;
}
