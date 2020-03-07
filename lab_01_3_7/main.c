#include<stdio.h>
#include<math.h>

double estimate(double x, double eps)
{
	long long i = 1;
	double t = x;
	double res = t;
	while (fabs(t) > eps)
	{
		i += 2;
		t *= (2 - i) * x * x / i;
		res += t;
	}
	return res;
}
int main(void)
{
    double sum_s, f_x, eps, abs_err, rel_err;
    double x;
    int r;

    printf("enter x and eps\n");
    r = scanf("%lf%lf", &x, &eps);
    if (r == 2)
    {
        if (eps >= 1 || eps <= 0)
        {
            printf("epsilon error");
            return 2;
        }
        else if (fabs(x) > 1)
        {
            printf("vlaue error");
            return 3;
        }
        else
        {
            sum_s = estimate(x, eps);
            f_x = atan(x);
            abs_err = fabs(f_x - sum_s);
            rel_err = fabs((f_x - sum_s) / f_x);
            printf("%lf %lf %lf %lf", sum_s, f_x, abs_err, rel_err);

            return 0;
        }
    }
    else
    {
        printf("input error");
        return 1;
    }
}
