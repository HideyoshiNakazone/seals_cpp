#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"
#include "global.h"

float a, b, c, d, n, m, integral;

int main()
{
    printf("------------------------------------------------");
    printf("\n\n\nProgram for Numeric Integrals: \n\n\n");

    printf("Insert the first interval of x: ");
    scanf("%f", &a);
    printf("Insert the last interval of x: ");
    scanf("%f", &b);

    line();

    printf("Insert the first interval of y: ");
    scanf("%f", &c);
    printf("Insert the last interval of y: ");
    scanf("%f", &d);

    line();

    printf("Insert the number of patitions of x: ");
    scanf("%f", &n);
    printf("Insert the number of patitions of y: ");
    scanf("%f", &m);

    integral = riemann();

    line();

    printf("The integral is: %f", integral);

    line();

    return 0;
}
