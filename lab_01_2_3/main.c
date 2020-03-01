#include<stdio.h>
#include<math.h>

int main()
{
    float r1, r2, r3, r;
    scanf("%f%f%f", &r1, &r2, &r3);
    r = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r3 * r1);
    printf("%f", R);
    return 0;
}
