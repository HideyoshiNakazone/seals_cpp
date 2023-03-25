#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "bissec.h"

int main()
{
    int a, b, e;

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

        printf("Raiz é igual a: %f", bissecc(a, b, e));


    return 0;
}
