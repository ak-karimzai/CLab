#include<stdio.h>
#include<math.h>

float estimate(float x, float eps)
{
    float s_part = x;
    float s_sum = 0;
    int n = 1;

    while (fabsf(s_part) > eps)
    {
        s_sum += s_part;
        s_part = powf(-1, n) * powf(x, 2 * n + 1) / (2 * n + 1);
        n += 1;
    }
    return s_sum;
}
int main(void)
{
    float sum_s, f_x, eps, abs_err, rel_err;
    float x;
    int r;

    printf("enter x and eps\n");
    r = scanf("%f%f", &x, &eps);
    if (r == 2)
    {
        if (eps >= 1 || eps <= 0)
        {
            printf("epsilon error");
            return 2;
        }
        else if (fabsf(x) > 1)
        {
            printf("vlaue error");
            return 3;
        }
        else
        {
            sum_s = estimate(x, eps);
            f_x = atanf(x);
            abs_err = fabsf(f_x - sum_s);
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
