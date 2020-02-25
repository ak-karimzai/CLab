#include<stdio.h>
#include<math.h>

float series_estimate(float x, float eps)
{
    float series_part = x;
    float series_sum = x;
    int n = 1,m = 2;

    while (fabsf(series_part) > eps)
    {
        series_part *= ((n * pow(x, 2 * n + 1)) / n);
        series_sum += series_part;
        m += 2;
        n += 2;
    }
    return series_sum;
}
int main(void)
{
    float sum_s,eps;
    float x;

    printf("enter x and eps\n");
    scanf("%f%f",&x,&eps);
    if(x > 1 || x < -1)
    {
        printf("Epsilon error or x value invalid");
    }
    else
    {
    	sum_s = series_estimate(x,eps);
    	printf("%f",sum_s);
    }
}
