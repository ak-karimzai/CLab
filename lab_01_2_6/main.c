#include<stdio.h>
#include<math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, xp, yp, r, a, b, c, s;
    printf("Enter coordinate of point's and then coordinates of triangle: ");
    r = scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp);
    a = (x1 - xp) * (y2 - y1) - (x2 - x1) * (y1 - yp);
    b = (x2 - xp) * (y3 - y2) - (x3 - x2) * (y2 - yp);
    c = (x3 - xp) * (y1 - y3) - (x1 - x3) * (y3 - yp);
    s = (x1 * y2 + x2 * y3 + x3 * y1) / 2 - (x2 * y1 + x3 * y2 + x1 * y3);
    if (s <= 0)
    {
        printf("not triangle");
        return 3;
    }
    if (r == 8)
    {
        if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
        {
            if(a==0 || b==0 || c==0)
                printf("0");
            else
                printf("1");
        }
        else
            printf("2");
    }
    else
    {
        printf("input error");
        return 3;
    } 
}
