#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <sys/time.h>

#define N 1100
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
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int bouble_sort(int *a, int n)
{
    int flag = 0, i, j;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
    }
    return flag;
}
void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time;
    int a[N] = { 0 };
    int n;
    printf("Enter the size of array.\n");
    if (read_array(a, &n))
    {
        return LOG_ERROR;
    }
    else
    {
        gettimeofday(&tv_start, NULL);
        bouble_sort(a, n);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
        printf("%" PRId64 " µs\n", elapsed_time);
        return 0;
    }
}