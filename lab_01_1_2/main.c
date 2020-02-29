#include<stdio.h>
#include<math.h>

float surface_trapezoid()
{
    float d1, d2, s, a;
    scanf("%f%f%f", &d1, &d2, &a);
    a = a * 3.14 / 180;
    s = 1 / 2 * d1 * d2 * sin(a);
    return s;
}
int main()
{
    float x;
    x = surface_trapezoid();
    printf("%.4f", x);
}