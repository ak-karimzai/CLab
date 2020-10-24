#include <stdlib.h>
#include "../inc/key.h"

int get_num_of_elements(const int *arr_lhs, const int *arr_rhs, int *sum)
{
    int count = 0;
    *sum = 0;
    for (const int *p = arr_lhs; p != arr_rhs; p++)
    {
        *sum += *p;
    }

    if (*sum == 0)
        return count;

    int tmp_sum = *sum;
    for (const int *p = arr_lhs; p != arr_rhs - 1; p++)
    {
        tmp_sum -= *p;
        if (*p > tmp_sum)
            count++;
    }
    return count;
}

void add_elements_to_array(int *dst_arr, const int *src_arr_lhs, const int *src_arr_rhs, int sum)
{
    int i = 0;
    for (; src_arr_lhs != src_arr_rhs - 1; src_arr_lhs++)
    {
        sum -= *src_arr_lhs;
        if (*(src_arr_lhs) > sum)
            *(dst_arr + i++) = *src_arr_lhs;
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = ok;
    int count = 0, sum;
    *pb_dst = *pe_dst = NULL;
    if (!pb_src || pe_src - pb_src <= 0)
        rc = error;
    else
    {
        count = get_num_of_elements(pb_src, pe_src, &sum);
        if (count == 0)
            rc = error;
        else
        {
            *pb_dst = malloc(count * sizeof(int));
            if (*pb_dst == NULL)
                rc = error;
            else
            {
                add_elements_to_array(*pb_dst, pb_src, pe_src, sum);
                *pe_dst = *pb_dst + count;
            }
        }
    }
    return rc;
}