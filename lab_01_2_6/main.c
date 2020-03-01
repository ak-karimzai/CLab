#include<stdio.h>
#include<math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, ab, ac, bc, p, xp, yp, sab, sac, sbc, r;
    float s = 0, sum_all;
    printf("Enter coordinate of point's and then coordinates of triangle: ");
    r = scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp);
    ab = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    ac = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    bc = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    p = (ab + ac + bc) / 2;
    s = sqrt(p * (p - ab) * (p - ac) * (p - bc));
    sab = (x1 * (y2 - yp) + x2 * (yp - y1) + xp * (y1 - y2)) / 2.0;
    sbc = (xp * (y2 - y3) + x2 * (y3 - yp) + x3 * (yp - y2)) / 2.0;
    sac = (x1 * (yp - y3) + xp * (y3 - y1) + x3 * (y1 - yp)) / 2.0;
    sum_all = fabsf((fabsf(sab) + fabsf(sbc) + fabsf(sac)) - s);
    if (s == 0)
    {
        printf("not triangle");
        return 4;
    }
    else 
    {
        if (r == 8)
        {
            if ((xp == x1 && yp == y1) || (xp == x2 && yp == y2) || (xp == x3 && yp == y3) && sum_all < (1e-1))
                printf("1");
            else if((xp < x1 && yp == y1 || xp == x1 && yp < y1) || (xp < x2 && yp == y2 || xp == x2 && yp < y2) || (xp < x3 && yp == y3 || xp == x3 && yp < y3))
                printf("1");
            else if (sum_all < (1e-1))
                printf("0");
            else
                printf("2");
        }
        else
        {
            printf("input error");
            return 3;
        }
    }   
}