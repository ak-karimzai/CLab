#include<stdio.h>
#include<math.h>

int main()
{
    float R1, R2, R3, R;
    scanf("%f%f%f", &R1, &R2, &R3);
    R = (R1 * R2 * R3) / (R1 * R2 + R2 * R3 + R3 * R1);
    printf("%f", R);
    return 0;
}
