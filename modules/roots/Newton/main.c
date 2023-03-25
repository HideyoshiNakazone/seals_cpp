#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float f(float x)
{
    float y;
    y = sin(pow(x,2));

return y;
}

float d(float a)
{
    float dy;

    dy = 2*a*cos(pow(a,2)) ;

return dy;
}

float bissecc(float a, float e)
{
    float x, b, fa, fx, da;

    fa=f(a);
    fx=f(x);
    da=d(a);
    b=x;
    x=0;

    while(fabs(b-a)>e)
    {

    b=x;
    x = a - (fa/da);
    a=x;
    fa=f(a);
    da=d(a);

    }

return x;
}

int main()
{
setlocale(LC_ALL,"portuguese");

    float a, x, e;

    printf("Metodo de Newton\n\n");
    printf("Digite seu Xo: ");
    scanf("%f", &a);
    printf("Digite a precisão: ");
    scanf("%f", &e);

    x=bissecc(a,e);
    printf("Raiz aproximada = %.10f", x);

return 0;
}
