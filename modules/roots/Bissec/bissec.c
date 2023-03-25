#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "bissec.h"

float f(float x)
{
    float y;
    y = sin(pow(x,2));
    return y;

}
float bissecc(float a,float b,float e)
{
    float c, fa, fb, fc;

    fa=f(a);
    fb=f(b);

    while(fabs(b-a)>e)
    {

        c=(a+b)/2;
        fc=f(c);
        
        if(fa*fc<0)
        {
            b = c;
            fb=fc;
        }
        else
        {
            a=c;
            fa=fc;
        }

    }

    c=(a+b)/2;

    return c;
}