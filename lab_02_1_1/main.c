#include <stdio.h>
#include <math.h>
#define N 10
#define SIZE_ERROR -1
#define ELEMENT_ERROR -2
#define ARRAY_N_FULL -3
#define INCORRECT_S_INPUT -4
#define INPUT_ERROR -5
#define LOG_ERROR -6

int read_array(int *const a, int *n)
{
    int rc, array_i;
    int count = 0;
    rc = scanf("%d", n);
    if (rc == 1)
    {
        if (*n > N || * n < 1)
        {
            printf("invlaid Input for size");
            return SIZE_ERROR;
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
                    printf("Invalid element input");
                    return ELEMENT_ERROR;
                }
            }
            if (count != *n)
            {
                printf("Array not full");
                return ARRAY_N_FULL;
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
        return INCORRECT_S_INPUT;
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
    if (even_counter == 0)
    {
        printf("Array without event numbers");
        geo_av = 0;
        return LOG_ERROR;
    }
    return geo_av;
}
int main()
{
    int a[N] = { 0 }, n = 0;

    if (read_array(a, &n))
    {
        return INPUT_ERROR;
    }
    else
    {
        const float geo_avr = geo_averge(a, n);

        if (geo_avr == LOG_ERROR)
        {
            return LOG_ERROR;
        }
        else
        {
            printf("%.4f", geo_avr);
            return 0;
        }
    }
}
