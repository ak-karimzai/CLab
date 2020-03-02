#include <stdio.h>
#include <math.h>


int string_hello(char string , float *x_point, float *y_point)
{
    printf("Input triangle coordinates(x, y) point %c: ", string);
    if (scanf("%f %f", x_point, y_point) == 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int print_error(char string)
{
    printf("\nError input point %c!", string);
    return 1;
}
int if_tri(float x_1, float y_1, float x_2, float y_2);

int give_information(float x1, float y1, float x2, float y2,
                      float x3, float y3, float xp, float yp);
int main(void)
{
    int rc = 0, flag;
    float x1, y1, x2, y2, x3, y3;
    float xp, yp;
    
    rc = string_hello('A', &x1, &y1);
    if (rc)
        return print_error('A');
    rc = string_hello('B', &x2, &y2);
    if (rc)
        return print_error('B');
    rc = string_hello('C', &x3, &y3);
    if (rc)
        return print_error('C');
    if (!(if_tri(x2 - x1, y2 - y1, x1 - x3, y1 - y3)))
    {
        printf("Input coordinates(x, y) point O: ");
        if (scanf("%f %f", &xp, &yp) == 2)
            flag = give_information(x1, y1, x2, y2, x3, y3, xp, yp);
        else
            return print_error('O');
    }
    else
    {
        printf("Error triagle!");
        return 1;
    }
    if (flag == 2)
    {
        printf("0");
    }
    else if (flag == 3)
    {
        printf("1");
    }
    else
    {
        printf("2");
    }
}

int if_tri(float x_1, float y_1, float x_2, float y_2)
{
    if ((fabs(x_1*y_2 - x_2*y_1)) <= 0.00001)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int find_point(float x_1, float y_1, float x_2, float y_2)
{
    if ((x_1*y_2 - x_2*y_1) > 0)
    {
        return 1;
    }
    else if ((x_1*y_2 - x_2*y_1) < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int give_information(float x1, float y1, float x2, float y2,
                      float x3, float y3, float xp, float yp)
{
    int s1, s2, s3, flag;
    s1 = find_point(x2 - x1, y2 - y1, xp - x1, yp - y1);
    s2 = find_point(x3 - x2, y3 - y2, xp - x2, yp - y2);
    s3 = find_point(x1 - x3, y1 - y3, xp - x3, yp - y3);
    if ((s1 < 0 && s2 < 0 && s3 < 0) ||
            (s1 > 0 && s2 > 0 && s3 > 0))
    {
        flag = 2;
    }
    else if (s1 == 0 || s2 == 0 || s3 == 0)
    {
        flag = 3;
    }
    else
    {
        flag = 4;
    }
    return flag;
}