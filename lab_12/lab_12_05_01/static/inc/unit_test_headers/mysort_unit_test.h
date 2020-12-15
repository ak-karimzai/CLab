#ifndef MY_SORT_UNIT_TEST_H
#define MY_SORT_UNIT_TEST_H

#include <check.h>
#include <stdlib.h>

#include "../sort.h"
#define EPS 1e-6
#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

SUITE *mysort_unit_tests_suite(void);
int mysort_sort_tests(void);


#endif //