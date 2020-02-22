#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float surface_trapezoid()
{
    float d1,d2,s;
    double a;
    scanf("%f%f%lf",&d1,&d2,&a);
    s = ((d1 * d2 / 2) * (sin(a)));
    return s;
}
int main()
{
    float x;
    x = surface_trapezoid();
    printf("%.4f",x);
}