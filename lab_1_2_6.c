#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float x1,y1,x2,y2,x3,y3,ab,ac,bc,p,xp,yp,sab,sac,sbc;
    float s = 0, sum_s = 0;
    printf("Enter first point's\n");
    scanf("%f%f",&x1,&y1);
    printf("Enter second point's\n");
    scanf("%f%f",&x2,&y2);
    printf("Enter third point's\n");
    scanf("%f%f",&x3,&y3);
    ab = sqrt(pow(x2-x1,2) + pow(y2 - y1,2));
    ac = sqrt(pow(x3-x1,2) + pow(y3 - y1,2));
    bc = sqrt(pow(x3 - x2,2) + pow(y3 - y2,2));
    p = (ab + ac + bc) / 2;
    s = sqrt(p * (p - ab) * (p - ac) * (p - bc));

    printf("Enter coordinate of point's\n");
    scanf("%f%f",&xp,&yp);

    sab = (x1 * (y2 - yp) + x2 * (yp - y1) + xp * (y1 - y2))/2;
    sbc = (xp * (y2 - y3) + x2 * (y3 - yp) + x3 * (yp - y2))/2;
    sac = (x1 * (yp - y3) + xp * (y3 - y1) + x3 * (y1 - yp))/2;

    

    if(abs((abs(sab) + abs(sbc) + abs(sac)) - s) < (1e-1)) printf("point in triangle.\n");
    else printf("point is'nt triangle\n");
}