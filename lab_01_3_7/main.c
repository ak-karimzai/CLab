#include <stdio.h>
#include <math.h>

#define OK 0
#define IN_ERR 1
#define LOGIC_ERR 2

float series_estimate(float x, float eps)
{
    float s_part = x;
    float s_sum = x;
    int n = 3;

    while (fabsf(s_part) > eps)
    {
        s_part *= -1 * x * x / n;
        s_sum += s_part;
        n += 2;
    }
    return s_sum;
}

int main()
{
    int rc;
    float x, eps;
    float s_x, f_x, abs_err, rel_err;

    rc = scanf("%f%f", &x, &eps);

    if (rc == 2)
    {
        if (eps > 1 || eps <= 0)
        {
            printf("Epsilon error");

            return LOGIC_ERR;
        }
        else
        {
            s_x = series_estimate(x, eps);
            f_x = atanf(x);
            abs_err = fabsf(f_x - s_x);
            rel_err = fabsf((f_x - s_x) / f_x);

            printf("%f %f %f %f", s_x, f_x, abs_err, rel_err);

            return OK;
        }
    }
    else
    {
        printf("Input error");

        return IN_ERR;
    }
}