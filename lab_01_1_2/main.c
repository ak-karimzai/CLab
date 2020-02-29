#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, s, d, h;
    scanf("%f%f%f", &a, &b, &d);
    d = d * 3.14 / 180;
    h = (a - b) * sinf(d) / (2 * cosf(d));
    s = (a + b) * h / 2;
    printf("%.4f", s);
}