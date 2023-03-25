#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"
#include "global.h"

/*GLOBAL VARIABLES*/
float a, b, n, dx;

int main()
{
    printf("------------------------------------------------");
    printf("\n\n\nProgram for Numeric Integrals: \n\n\n");

    float integral;

    printf("Insert the first interval: ");
    scanf("%f", &a);
    printf("Insert the last interval: ");
    scanf("%f", &b);

    line();

    printf("Insert the number of patitions: ");
    scanf("%f", &n);

    line();

    integral = simpson();

    printf("The integral is: %.10f", integral);

    line();
    line();

    printf("------------------------------------------------");

    return 0;
}
