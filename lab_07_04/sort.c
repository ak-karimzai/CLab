#include <string.h>
#include <stdlib.h>

typedef int (*compare)(void *lhs, void *rhs);

void swap_all_types(void *lhs, void *rhs, const size_t size)
{
    void *tmp = malloc(size);
    memcpy(tmp, lhs, size);
    memcpy(lhs, rhs, size);
    memcpy(rhs, tmp, size);
    free(tmp);
}

int compare_int(void *lhs, void *rhs)
{
    return *(int *)(lhs) < *(int *)(rhs);
}

int compare_char(void *lhs, void *rhs)
{
    return *(char *)(lhs) < *(char *)(rhs);
}

char *charof(void *pointer, const int iteration, const size_t size)
{
    return (char *)(pointer) + iteration * size;
}

void mysort(void *arr_lhs, size_t num_of_elements, const size_t size, compare comp)
{
    int k;
    for (int i = 0; i < num_of_elements - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < num_of_elements; j++)
        {
            if (comp(charof(arr_lhs, j, size), charof(arr_lhs, k, size)))
                k = j;
        }
        swap_all_types(charof(arr_lhs, i, size), charof(arr_lhs, k, size), size);
    }
}