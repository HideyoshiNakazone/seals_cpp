#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float f(float x)
{
    float y;

    y = sin(pow(x,2));

    return y;

}

float d(float x)
{
    float dy;

    dy = 2*x*cos(pow(x,2)) ;

return dy;
}

float calc(float a, float b, float e)
{
    float c, fa, fb, fc, x, dc;

    fa=f(a);
    fb=f(b);

    c=(a+b)/2;

    while(fabs(b-a)>(0.1))
    {

    fc=f(c);

    if(fa*fc<0)
    {
    b = c;
    fb=f(b);
    }
    else
    {
    a=c;
    fa=f(a);
    }

    c=(a+b)/2;

    }

    x=0;
    fc=f(c);
    dc=d(c);

    while(fabs(x-c)>e)
    {
    x = c - (fc/dc);
    c=x;
    fc=f(c);
    dc=d(c);
    }

    return c;
}

int main()
{

setlocale(LC_ALL, "");

    float a, b, e, resultado;

    printf("Programa de Calculo de Raiz:\n\n");
    printf("Insira o valor do primeiro intervalo:");
    scanf("%f", &a);
    printf("Insira o segundo valor do intervalo:");
    scanf("%f", &b);
    printf("Insira o Erro da Operação:");
    scanf("%f", &e);

        if(f(a)*f(b)>0)
    {
        printf("O intervalo não é aplicavel\n Digite um novo intervalo: \n");
        printf("Digite o primeiro elemento do intervalo: ");
        scanf("%f", &a);
        printf("Digite o segundo elemento do intervalo: ");
        scanf("%f", &b);
    }

    resultado = calc(a, b, e);

    printf("Raiz é igual a: %f", resultado);

    return 0;
}
