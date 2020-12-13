#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <stdlib.h>

typedef int (*compare)(const void *lhs, const void *rhs);
int compare_int(const void *lhs, const void *rhs);
void mysort(void *arr_lhs, size_t num_of_elements, const size_t size, compare comp);

#endif // SORT_H