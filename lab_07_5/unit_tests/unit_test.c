#include "main.h"
#include "unit_function.h"
#include <assert.h>
#include <check.h>
#include <stdio.h>

START_TEST(check_file_count_obj_fun)
{
    FILE *check_file = fopen("../functional_tests/pos_in_1.txt");
    int rc = file_count_objs(check_file);
    ck_assert_int_eq(10, rc);
}
END_TEST

START_TEST(check_if_file_is_emtpy)
{
    FILE *check_file = fopen("../functional_tests/neg_in_1.txt");
    int rc = file_count_objs(check_file);
    ck_assert_int_eq(0, rc);
}
END_TEST

START_TEST(check_positive_res_of_get_num_of_elem_greather_than_sum_of_next_elements_no1)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int temp_sum;
    int rc = get_num_of_elements_bigger_than_all_next(arr, arr + 10, &temp_sum);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(check_positive_res_of_get_num_of_elem_greather_than_sum_of_next_elements_no2)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int temp_sum;
    int rc = get_num_of_elements_bigger_than_all_next(arr, arr + 10, &temp_sum);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(check_key_works_correctly_no1)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *arr_lhs = NULL, *arr_rhs = NULL;
    int res_arr[] = {2};
    int function_res = key(arr, arr + 10, &arr_lhs, &arr_rhs);
    ck_assert_int_eq(function_res, 0);
    for (int *p = arr_lhs, i = 0; arr_lhs != arr_rhs; p++)
        ck_assert_int_eq(*p, res_arr[i++])
}
END_TEST

START_TEST(check_key_works_correctly_no1)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *arr_lhs = NULL, *arr_rhs = NULL;
    int res_arr[] = {2};
    int function_res = key(arr, arr + 10, &arr_lhs, &arr_rhs);
    ck_assert_int_eq(function_res, 0);
    for (int *p = arr_lhs, i = 0; arr_lhs != arr_rhs; p++)
        ck_assert_int_eq(*p, res_arr[i++])
}
END_TEST

Suite *calc_file_check(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("file_count_obj");
    
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, check_file_count_obj_fun);
    tcase_add_test(tc_pos, check_if_file_is_emtpy);
    
    suite_add_tcase(s, tc_pos);
    return s;
}

int main()
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = calc_file_check();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return no_failed == 0 ? 0 : 1;
}