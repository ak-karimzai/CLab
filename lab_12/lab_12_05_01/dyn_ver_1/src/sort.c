#include "../inc/sort.h"

void swap(void *lhs, void *rhs, size_t size)
{
    void *tmp = calloc(size, sizeof(char));
    memcpy(tmp, lhs, size);
    memcpy(lhs, rhs, size);
    memcpy(rhs, tmp, size);
    free(tmp);
}

LIB_DLL int DLL_DECL compare_int(const void *lhs, const void *rhs)
{
    return *(int *)(lhs) - *(int *)(rhs);
}

char *charof(void *pointer, const int iteration, const size_t size)
{
    return (char *)(pointer) + iteration * size;
}

LIB_DLL void DLL_DECL mysort(void *arr_lhs, const size_t num_of_elements, const size_t size, compare comp)
{
    if (num_of_elements != 0)
    {
        int k;
        for (int i = 0; i < num_of_elements - 1; i++)
        {
            k = i;
            for (int j = i + 1; j < num_of_elements; j++)
            {
                if (comp(charof(arr_lhs, j, size), charof(arr_lhs, k, size)) <= -1)
                    k = j;
            }
            swap(charof(arr_lhs, i, size), charof(arr_lhs, k, size), size);
        }
    }
}