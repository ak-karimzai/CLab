#include <check.h>
#include <stdlib.h>
#include "../inc/mysort_unit_test.h"

START_TEST(check_sorted_array)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int dst_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    mysort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare_int);
    for (int i = 0; i < 10; i++)
        ck_assert_int_eq(arr[i], dst_arr[i]);
}
END_TEST

START_TEST(check_back_sorted_array)
{
    int arr[] = {-10, -20, 10, 9, 8, 7, 6, 5, 4, 3, 2 ,1};
    const int dst_arr[] = {-20, -10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    mysort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare_int);
    for (int i = 0; i < 12; i++)
        ck_assert_int_eq(arr[i], dst_arr[i]);
}
END_TEST

START_TEST(check_random_array)
{
    int arr[] = {-96, 77, -66, -44, 37, 28, 80, -38, 31, 55};
    const int dst_arr[] = {-96, -66, -44, -38, 28, 31, 37, 55, 77, 80};
    
    mysort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare_int);
    for (int i = 0; i < 10; i++)
        ck_assert_int_eq(arr[i], dst_arr[i]);
}
END_TEST

Suite *test_my_sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort function");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, check_random_array);
    tcase_add_test(tc_pos, check_sorted_array);
    tcase_add_test(tc_pos, check_back_sorted_array);

    suite_add_tcase(s, tc_pos);
    return s;
}

int calc_sort_test()
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_my_sort_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return no_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}