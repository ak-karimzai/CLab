#include<stdio.h>
#include<math.h>

float surface_trapezoid()
{
    float d1, d2, s, a;
    scanf("%f%f%f", &d1, &d2, &a);
    a = a * 3.14 / 180;
    s = ((d1 + d2) / 2) * (sin(a) / cos(a) * (d2 - d1) / 2);
    return s;
}
int main()
{
    float x;
    x = surface_trapezoid();
    printf("%.4f", x);
}