#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>

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
        if (*n > N || *n < 1)
        {
            printf("invalid input for size");
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
                    printf("invalid element input");
                    return ELEMENT_ERROR;
                }
            }
            if (count != *n)
            {
                printf("array not full");
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
        printf("incorect input Size");
        return INCORRECT_S_INPUT;
    }
}
void process_1(int *begin, int *end)
{
    int *m = ++begin;
    int min = (*(m - 1) * *m);
    for (int *i = ++begin; i != end; i++)
    {
        if ((*(i - 1) * *i) < min)
            min = (*(i - 1) * *i);
    }
}
void process_2(int a[], int n)
{
    int min = (a[0] * a[1]);
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] * a[i + 1]) < min) 
            min = (a[i] * a[i + 1]);
    }
}
int process_3(int *a, int n)
{
    int min = a[0] * a[1];
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] * a[i + 1]) < min)
        {
            min = (a[i] * a[i + 1]);
        }
    }
}
int main()
{
    int a[N], n;
    long num = 1000000;
    struct timeval start, stop;
    int64_t work;
    if (read_array(a, &n))
    {
        return LOG_ERROR;
    }
    else
    {
        if (n == 1)
        {
            printf("array only with one element");
            return INPUT_ERROR;
        }
        gettimeofday(&start, NULL);
        for (int i = 0; i < num; i++)
            process_2(a, n);
        gettimeofday(&stop, NULL);
        work = (stop.tv_sec - start.tv_sec) * 1000000LL + (stop.tv_usec - start.tv_usec);
        printf("by index: %" PRId64 " µs\n", work);
        
        gettimeofday(&start, NULL);
        for (int i = 0; i < num; i++)
            process_1(a, (a + n));
        gettimeofday(&stop, NULL);
        work = (stop.tv_sec - start.tv_sec) * 1000000LL + (stop.tv_usec - start.tv_usec);
        printf("by pointer: %" PRId64 " µs\n", work);

        gettimeofday(&start, NULL);
        for (int i = 0; i < num; i++)
            process_3(a, n);
        gettimeofday(&stop, NULL);
        work = (stop.tv_sec - start.tv_sec) * 1000000LL + (stop.tv_usec - start.tv_usec);
        printf("*(i + 1): %" PRId64 " µs\n", work);
    }
}