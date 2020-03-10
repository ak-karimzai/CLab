#include <stdio.h>
#include <math.h>
#define N 10
#define size_error -1
#define element_error -2
#define array_nfull -3
#define incorect_sinput -4
#define input_error -5
#define log_error -6

int read_array(int *const a, int *n)
{
    int rc, array_i;
    int count = 0;
    rc = scanf("%d", n);
    if(rc == 1)
    {
        if (*n > N || * n < 1)
        {
            printf("invlaid Input for size");
            return size_error;
        }
        else
        {
            for (int i = 0; i < *n; i++)
            {
                rc = scanf("%d", &array_i);
                if (rc == 1)
                {
                    a[i] = array_i;
                    count++;
                }
                else
                {
                    printf("Invalid element input")
                    return element_error;
                }
            }
            if (count != *n)
            {
                printf("Array not full");
                return array_nfull;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        printf("incorrect input Size");
        return incorrect_sinput;
    }
}
int geo_averge(const int *const a, const int n)
{
    float geo_av = 1;
    int even_counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            even_counter++;
            geo_av *= a[i];
        }
    }
    if(even_counter == 0)
    {
        printf("Array without event numbers");
        geo_av = 0;
        return log_error;
    }
    return geo_av;
}
int main()
{
    int a[N] = {0}, n = 0;

    if (read_array(a, &n))
    {
        return input_error;
    }
    else
    {
        const float geo_avr = geo_averge(a, n);

        if (geo_avr == log_error)
        {
            return log_error;
        }
        else
        {
            printf("%.4f", geo_avr);
            return 0;
        }
    }
}
