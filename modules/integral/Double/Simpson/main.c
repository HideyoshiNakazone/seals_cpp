#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"
#include "global.h"

/* GLOBAL VARIABLES */
double a, b, c, d, n, m, dx, dy;

int main()
{
    printf("------------------------------------------------");
    printf("\n\n\nProgram for Numeric Integrals: \n\n\n");

    printf("Insert the first interval of x: ");
    scanf("%lf", &a);
    printf("Insert the last interval of x: ");
    scanf("%lf", &b);

    line();

    printf("Insert the first interval of y: ");
    scanf("%lf", &c);
    printf("Insert the last interval of y: ");
    scanf("%lf", &d);

    line();

    printf("Insert the number of patitions of x: ");
    scanf("%lf", &n);
    printf("Insert the number of patitions of y: ");
    scanf("%lf", &m);

    double integral = simpson(a,b,c,d,n,m);

    line();

    printf("The integral is: %lf", integral);

    line();

    return 0;
}
