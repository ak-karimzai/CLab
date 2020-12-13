#include "../inc/arr_operation.h"

int left_rotation(int *arr, int size, int pos)
{
    int rc = ok;
    if (size > 0)
    {
        int temp, i, j;
        i = j = 0;
        while (i < pos)
        {
            temp = arr[0];
            for (j = 0; j < size - 1; j++)
                *(arr + j) = *(arr + (j + 1));
            *(arr + j) = temp;
            i++;
        }
    }
    else
        rc = error;
    return rc;
}

static int perf_num(int x)
{
    int rc = error;
    double y = (double)(x);
    if (sqrt(y) - y < 1e-6)
        rc = ok;
    return rc;
}

static int count_perf_nums(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (perf_num(*(arr + 1)) == ok)
            count++;
    return count;
}

int copy_perf_nums(int *arr, int arr_size, int *arr_dst, int dst_size)
{
    int count = count_perf_nums(arr, arr_size);
    int rc = ok;
    if (dst_size != count)
    {
        for (int i = 0, j = 0; i < arr_size; i++)
            if (perf_num(*(arr + i)) == ok)
                *(arr_dst + j++);
    }
    else
        rc = count;
    return rc;
}