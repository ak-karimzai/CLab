#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/unit_test_headers/mysort_unit_test.h"

#define START START_TEST
#define END END_TEST
#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

START(when_dimension_are_not_eq)
{
    FILE *first = fopen("../func_tests/mat_1.txt", "r");
    FILE *second = fopen("../func_tests/mat_2.txt", "r");
    ck_assert_ptr_ne(first, NULL);    
    ck_assert_ptr_ne(second, NULL);
    matrix *lhs_mat = get_matrix_from_file(first);    
    matrix *rhs_mat = get_matrix_from_file(second);

    mysort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare_int);
    for (int i = 0; i < num_of_ele - 1; i++)
        ck_assert_int_le(arr[i], arr[i + 1]);
}
END

START(check_back_sorted_array)
{
    int arr[] = { -10, -20, 10, 9, 8, 7, 6, 5, 4, 3, 2 ,1 };
    const int num_of_elems = 12;
    
    mysort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare_int);
    for (int i = 0; i < num_of_elems - 1; i++)
        ck_assert_int_le(arr[i], arr[i + 1]);
}
END

START(check_random_array)
{
    int arr[] = { -96, 77, -66, -44, 37, 28, 80, -38, 31, 55 };
    const int num_of_elems = 10;

    mysort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare_int);
    for (int i = 0; i < num_of_elems - 1; i++)
        ck_assert_int_le(arr[i], arr[i + 1]);
}
END

SUITE *mysort_unit_tests_suite(void)
{
    SUITE *s;
    TCASE *tc_pos;

    s = suite_create("mysort function");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, check_random_array);
    tcase_add_test(tc_pos, check_sorted_array);
    tcase_add_test(tc_pos, check_back_sorted_array);

    suite_add_tcase(s, tc_pos);
    return s;
}
