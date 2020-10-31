#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/unit_test_headers/addition_unit_tests.h"

void ck_assert_mat_sum_eq(matrix *lhs, matrix *rhs, matrix *res)
{
    for (int i = 0; i < res->row; i++)
        for (int j = 0; j < res->col; j++)
            ck_assert_float_eq(res->mat[i][j], lhs->mat[i][j] + rhs->mat[i][j]);
}

START(when_dimension_are_not_eq)
{
    FILE *first = fopen("../func_tests/mat_1.txt", "r");
    FILE *second = fopen("../func_tests/mat_2.txt", "r");
    ck_assert_ptr_ne(first, NULL);    
    ck_assert_ptr_ne(second, NULL);

    matrix *lhs_mat = get_matrix_from_file(first);    
    matrix *rhs_mat = get_matrix_from_file(second);

    ck_assert_ptr_ne(lhs_mat, NULL);
    ck_assert_ptr_ne(rhs_mat, NULL);

    matrix *res = addition(lhs_mat, rhs_mat);
    ck_assert_ptr_eq(res, NULL);

    close_if_opened_file(first);
    close_if_opened_file(second);
    
    free_mat_if_not_null(lhs_mat);
    free_mat_if_not_null(rhs_mat);
    free_mat_if_not_null(res);
}
END

START(when_dimension_are_equal)
{
    FILE *first = fopen("../func_tests/mat_1.txt", "r");
    FILE *second = fopen("../func_tests/mat_3.txt", "r");

    ck_assert_ptr_ne(first, NULL);    
    ck_assert_ptr_ne(second, NULL);
    
    matrix *lhs_mat = get_matrix_from_file(first);    
    matrix *rhs_mat = get_matrix_from_file(second);

    ck_assert_ptr_ne(lhs_mat, NULL);
    ck_assert_ptr_ne(rhs_mat, NULL);

    matrix *res = addition(lhs_mat, rhs_mat);
    ck_assert_ptr_ne(res, NULL);

    ck_assert_mat_sum_eq(lhs_mat, rhs_mat, res);

    close_if_opened_file(first);
    close_if_opened_file(second);
    
    free_mat_if_not_null(lhs_mat);
    free_mat_if_not_null(rhs_mat);
    free_mat_if_not_null(res);
}
END

SUITE *addition_unit_tests_suite(void)
{
    SUITE *s;
    TCASE *tc_pos;
    TCASE *tc_neg;

    s = suite_create("Addition");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, when_dimension_are_equal);

    tc_pos = tcase_create("negatives");
    tcase_add_test(tc_neg, when_dimension_are_not_eq);

    suite_add_tcase(s, tc_pos);
    return s;
}
