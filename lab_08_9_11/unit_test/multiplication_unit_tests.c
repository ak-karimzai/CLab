#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/unit_test_headers/multiplication_unit_tests.h"

#define START START_TEST
#define END END_TEST
#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

void ck_assert_mat_mul_eq(matrix *res_from_file, matrix *res)
{
    for (int i = 0; i < res->row; i++)
        for (int j = 0; j < res->col; j++)
            ck_assert_double_eq(res->mat[i][j], res_from_file->mat[i][j]);
}

START(when_dimen_not_for_division)
{
    FILE *first = fopen("../func_tests/mat_4.txt", "r");
    FILE *second = fopen("../func_tests/mat_5.txt", "r");
    ck_assert_ptr_ne(first, NULL);    
    ck_assert_ptr_ne(second, NULL);
    matrix *lhs_mat = get_matrix_from_file(first);    
    matrix *rhs_mat = get_matrix_from_file(second);

    ck_assert_ptr_ne(lhs_mat, NULL);
    ck_assert_ptr_ne(rhs_mat, NULL);

    matrix *res = multiplication(lhs_mat, rhs_mat);
    ck_assert_ptr_eq(res, NULL);

    close_if_opened_file(first);
    close_if_opened_file(second);
    
    free_mat_if_not_null(lhs_mat);
    free_mat_if_not_null(rhs_mat);
    free_mat_if_not_null(res);
}
END

START(when_dimen_are_suit_for_devi)
{
    FILE *first = fopen("../func_tests/mat_4.txt", "r");
    FILE *second = fopen("../func_tests/mat_6.txt", "r");

    ck_assert_ptr_ne(first, NULL);    
    ck_assert_ptr_ne(second, NULL);
    
    matrix *lhs_mat = get_matrix_from_file(first);    
    matrix *rhs_mat = get_matrix_from_file(second);

    ck_assert_ptr_ne(lhs_mat, NULL);
    ck_assert_ptr_ne(rhs_mat, NULL);

    matrix *res = multiplication(lhs_mat, rhs_mat);
    ck_assert_ptr_ne(res, NULL);

    ck_assert_mat_mul_eq(lhs_mat, rhs_mat);

    close_if_opened_file(first);
    close_if_opened_file(second);
    
    free_mat_if_not_null(lhs_mat);
    free_mat_if_not_null(rhs_mat);
    free_mat_if_not_null(res);
}
END

START(vector_on_matrix)
{
    FILE *first = fopen("../func_tests/mat_7.txt", "r");
    FILE *second = fopen("../func_tests/mat_4.txt", "r");

    ck_assert_ptr_ne(first, NULL);    
    ck_assert_ptr_ne(second, NULL);
    
    matrix *lhs_mat = get_matrix_from_file(first);    
    matrix *rhs_mat = get_matrix_from_file(second);

    ck_assert_ptr_ne(lhs_mat, NULL);
    ck_assert_ptr_ne(rhs_mat, NULL);

    matrix *res = multiplication(lhs_mat, rhs_mat);
    ck_assert_ptr_ne(res, NULL);

    ck_assert_mat_mul_eq(lhs_mat, rhs_mat);

    close_if_opened_file(first);
    close_if_opened_file(second);
    
    free_mat_if_not_null(lhs_mat);
    free_mat_if_not_null(rhs_mat);
    free_mat_if_not_null(res);
}
END

SUITE *multiplication_unit_tests_suite(void)
{
    SUITE *s;
    TCASE *tc_pos;
    TCASE *tc_neg;

    s = suite_create("multiplication");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, when_dimen_are_suit_for_devi);
    tcase_add_test(tc_pos, vector_on_matrix);

    tc_pos = tcase_create("negatives");
    tcase_add_test(tc_neg, when_dimen_not_for_division);

    suite_add_tcase(s, tc_pos);
    return s;
}
