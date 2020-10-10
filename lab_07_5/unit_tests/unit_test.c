#include <check.h>
#include <stdlib.h>
#include "../inc/key_unit_test.h"

#define START START_TEST
#define END END_TEST
#define SUITE Suite
#define SRUNNER SRunner
#define TCASE TCase
#define CKVER CK_VERBOSE

START(check_key_works_crctly)
{
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int *arr_lhs = NULL, *arr_rhs = NULL;
    int res_arr[] = { 2 };

    int function_res = key(arr, arr + 10, &arr_lhs, &arr_rhs);
    
    ck_assert_int_eq(function_res, ok);

    for (int *p = arr_lhs, i = 0; p != arr_rhs; p++)
        ck_assert_int_eq(*p, res_arr[i++]);

    free(arr_lhs);
}
END

START(key_fun_not_find_ele)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *arr_lhs = NULL, *arr_rhs = NULL;

    int function_res = key(arr, arr + 10, &arr_lhs, &arr_rhs);
    
    ck_assert_int_eq(function_res, error);
    
    ck_assert_ptr_eq(arr_lhs, NULL);
    
    ck_assert_ptr_eq(arr_rhs, NULL);
}
END

START(check_fun_acpt_invalid_data)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *arr_lhs = NULL, *arr_rhs = NULL;

    int function_res = key(arr + 10, arr, &arr_lhs, &arr_rhs);
    
    ck_assert_int_eq(function_res, error);
    
    ck_assert_ptr_eq(arr_lhs, NULL);
    
    ck_assert_ptr_eq(arr_rhs, NULL);
}
END

START(check_fun_accepts_null_ptr)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *arr_lhs = NULL, *arr_rhs = NULL;

    int function_res = key(NULL, arr + 10, &arr_lhs, &arr_rhs);
    
    ck_assert_int_eq(function_res, error);
    
    ck_assert_ptr_eq(arr_lhs, NULL);
    
    ck_assert_ptr_eq(arr_rhs, NULL);
}
END

SUITE *check_key_fun(void)
{
    SUITE *s;
    TCASE *tc_neg;
    TCASE *tc_pos;

    s = suite_create("key function");
    
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, check_key_works_crctly);
    
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, key_fun_not_find_ele);
    tcase_add_test(tc_neg, check_fun_acpt_invalid_data);
    tcase_add_test(tc_neg, check_fun_accepts_null_ptr);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

int main(void)
{
    int no_failed = 0;
    SUITE *s;
    SRUNNER *runner;

    s = check_key_fun();
    runner = srunner_create(s);

    srunner_run_all(runner, CKVER);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return no_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}