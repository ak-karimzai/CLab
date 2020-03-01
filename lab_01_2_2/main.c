#include<stdio.h>
#include<math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, ab, ac, bc, p;
    printf("Enter coordinate of point's and then coordinates of triangle: ");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
    ab = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    ac = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    bc = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    p = (ab + ac + bc) / 2;
    printf("parameter equal:\n");
    printf("%f", p);
    return 0;
}
