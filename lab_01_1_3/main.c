#include<stdio.h>
#include<math.h>

void sum_temperator()
{
    float v1, t1, v2, t2, v, t;
    scanf("%f%f%f%f", &v1, &t1, &v2, &t2);
    v = v1 + v2;
    t = ((t1 * v1) + (t2 * v2)) / v;
    printf("%.4f  %.4f", v, t);
}
int main()
{
    sum_temperator();
}
