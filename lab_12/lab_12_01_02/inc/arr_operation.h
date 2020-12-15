#ifndef _ARR_OPERATION_H_
#define _ARR_OPERATION_H_

#include <math.h>

enum error_type
{
    ok,
    error
};

int left_rotation(int *arr, int size, int pos);

int copy_perf_nums(int *arr, int arr_size, int *arr_dst, int dst_size);
#endif //_ARR_OPERATION_H_