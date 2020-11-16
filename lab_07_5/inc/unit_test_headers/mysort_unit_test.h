#ifndef MY_SORT_UNIT_TEST_H
#define MY_SORT_UNIT_TEST_H

#include <check.h>
#include <stdlib.h>

#include "../sort.h"
#define EPS 1e-6

Suite* mysort_suite(void);
int mysort_sort_tests(void);

#endif //