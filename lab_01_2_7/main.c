#include<stdio.h>
#include<math.h>

float estimate(float x, float eps)
{
    float series_part = x;
    float series_sum = series_part;
    int n = 1;

    while (fabsf(series_part) > eps)
    {
        series_part *= (((x * x) * n) / ((n + 1) * (n + 2)));
        series_sum += series_part;
        n += 2;
    }
    return series_sum;
}
int main(void)
{
    float sum_s, f_x, eps, r, abs_err, rel_err;
    float x;

    printf("enter x and eps\n");
    r = scanf("%f%f", &x, &eps);
    if (r == 2)
    {
        if (eps >= 1 || eps <= 0)
        {
            printf("epsilon error");
            return 2;
        }
        else if (fabsf(x) >= 1)
        {
            printf("vlaue error");
            return 3;
        }
        else
        {
            sum_s = estimate(x, eps);
            f_x = asinf(x);
            abs_err = fabs(f_x - sum_s);
            rel_err = fabsf((f_x - sum_s) / f_x);

            printf("%f %f %f %f", sum_s, f_x, abs_err, rel_err);
            return 0;
        }
    }
    else
    {
        printf("input error");
        return 1;
    }
}