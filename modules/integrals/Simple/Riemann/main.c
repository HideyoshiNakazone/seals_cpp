#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"

int main()
{
    printf("------------------------------------------------");
    printf("\n\n\nProgram for Numeric Integrals: \n\n\n");

    float a, b, n, integral;

    printf("Insert the first interval: ");
    scanf("%f", &a);
    printf("Insert the last interval: ");
    scanf("%f", &b);

    printf("Insert the number of patitions: ");
    scanf("%f", &n);

    integral = riemann(a,b,n);

    printf("The integral is: %f", integral);

    return 0;
}
