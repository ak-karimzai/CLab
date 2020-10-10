#include <check.h>
#include <stdlib.h>
#include "../inc/key_unit_test.h"

#define start_test START_TEST
#define end_test END_TEST
#define suite Suite
#define srunner SRunner
#define tcase TCase

start_test(check_key_works_correctly)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *arr_lhs = NULL, *arr_rhs = NULL;
    int res_arr[] = {2};

    int function_res = key(arr, arr + 10, &arr_lhs, &arr_rhs);
    
    ck_assert_int_eq(function_res, ok);

    for (int *p = arr_lhs, i = 0; p != arr_rhs; p++)
        ck_assert_int_eq(*p, res_arr[i++]);
        
    free(arr_lhs);
}
end_test


start_test(when_key_function_not_find_any_element)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *arr_lhs = NULL, *arr_rhs = NULL;

    int function_res = key(arr, arr + 10, &arr_lhs, &arr_rhs);
    ck_assert_int_eq(function_res, error);
    ck_assert_ptr_eq(arr_lhs, NULL);
    ck_assert_ptr_eq(arr_rhs, NULL);
}
end_test

start_test(check_when_function_accepts_unvalid_data_as_a_parameter)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *arr_lhs = NULL, *arr_rhs = NULL;

    int function_res = key(arr + 10, arr, &arr_lhs, &arr_rhs);
    ck_assert_int_eq(function_res, error);
    ck_assert_ptr_eq(arr_lhs, NULL);
    ck_assert_ptr_eq(arr_rhs, NULL);
}
end_test

start_test(check_when_function_accepts_null_ptr_as_a_paramenter)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *arr_lhs = NULL, *arr_rhs = NULL;

    int function_res = key(NULL, arr + 10, &arr_lhs, &arr_rhs);
    ck_assert_int_eq(function_res, error);
    ck_assert_ptr_eq(arr_lhs, NULL);
    ck_assert_ptr_eq(arr_rhs, NULL);
}
end_test

suite *check_key_fun(void)
{
    suite *s;
    tcase *tc_neg;
    tcase *tc_pos;

    s = suite_create("key function");
    
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, check_key_works_correctly);
    
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, when_key_function_not_find_any_element);
    tcase_add_test(tc_neg, check_when_function_accepts_unvalid_data_as_a_parameter);
    tcase_add_test(tc_neg, check_when_function_accepts_null_ptr_as_a_paramenter);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

int main(void)
{
    int no_failed = 0;
    suite *s;
    srunner *runner;

    s = check_key_fun();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return no_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
