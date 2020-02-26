#include<stdio.h>
#include<math.h>

float sum_temperator()
{
    float v1, t1, v2, t2, v, T;
    scanf("%f%f%f%f", &v1, &t1, &v2, &t2);
    v = v1 + v2;
    T = ((t1 * v1) + (t2 * v2)) / v;
    return T;
}
int main()
{
    float x;
    x = sum_temperator();
    printf("%.4f", x);
}