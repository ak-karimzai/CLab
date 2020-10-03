#ifndef MY_SORT_UNIT_TEST_H
#define MY_SORT_UNIT_TEST_H

typedef int (*compare)(void *lhs, void *rhs);
void mysort(void *arr_lhs, const size_t num_of_elements, const size_t size, compare comp);
int compare_int(void *lhs, void *rhs);

#endif //