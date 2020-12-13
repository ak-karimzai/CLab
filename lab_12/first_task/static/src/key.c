#include "../inc/key.h"

static int arr_sum(const int *arr_lhs, const int src_size)
{
    int sum = 0;
    for (int i = 0; i < src_size; i++)
        sum += *(arr_lhs + i);
    return sum;
}

static int get_num_of_elements(const int *arr_lhs, const int arr_size, int *sum)
{
    int count = 0;
    *sum = arr_sum(arr_lhs, arr_size);

    if (*sum != 0)
    {
        int tmp_sum = *sum;
        for (int i = 0; i < arr_size - 1; i++)
        {
            tmp_sum -= *(arr_lhs + i);
            if (*(arr_lhs + i) > tmp_sum)
                count++;
        }
    }
    return count;
}

static void add_elements_to_array(int *dst_arr, const int *src_arr_lhs, const int *src_arr_rhs, int sum)
{
    int i = 0;
    for (; src_arr_lhs != src_arr_rhs - 1; src_arr_lhs++)
    {
        sum -= *src_arr_lhs;
        if (*(src_arr_lhs) > sum)
            *(dst_arr + i++) = *src_arr_lhs;
    }
}

int key(const int *pb_src, const int src_size, int *pb_dst, int *prd_size)
{
    int rc = ok;
    int count = 0, sum;
    if (pb_src == NULL)
        rc = error;
    else
    {
        count = get_num_of_elements(pb_src, src_size, &sum);
        if (count == 0)
            rc = error;
        else
        {
            if (pb_dst == NULL || *prd_size < count)
                rc = count;
            else
            {
                add_elements_to_array(pb_dst, pb_src, pb_src + src_size, sum);
                *prd_size = count;
            }
        }
    }
    return rc;
}
