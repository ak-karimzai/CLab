#include<stdio.h>
#include<math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, xp, yp, r, ab, ac, bc, s, p;
    printf("Enter coordinate of point's and then coordinates of triangle: ");
    r = scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp);
    ab = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    ac = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    bc = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    p = (ab + ac + bc) / 2;
    s = sqrt(p * (p - ab) * (p - ac) * (p - bc));
    if (s == 0)
    {
        printf("not triangle");
        return 4;
    }
    if (r == 8)
    {
        if ((xp == x1 && yp == y1) || (xp == x2 && yp == y2) || (xp == x3 && yp == y3))
        {
            printf("1");
        }
        else
        {    
            printf (
                (((xp - x1) * (y2 - y1) - (yp - y1) * (x2 - x1)) * ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) >= 0) &&
                (((xp - x2) * (y3 - y2) - (yp - y2) * (x3 - x2)) * ((x1 - x2) * (y3 - y2) - (y1 - y2) * (x3 - x2)) >= 0) &&
                (((xp - x3) * (y1 - y3) - (yp - y3) * (x1 - x3)) * ((x2 - x3) * (y1 - y3) - (y2 - y3) * (x1 - x3)) >= 0 )? 
                "0": "2");
        }
    }
    else
    {
        printf("input error");
        return 3;
    } 
}
