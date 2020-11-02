#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/unit_test_headers/gauss_unit_tests.h"

void ck_assert_mat_eq(matrix *res, matrix *file_res)
{
    ck_assert_int_eq(file_res->col, 1);
    ck_assert_int_eq(file_res->row, res->row);
    for (int i = 0; i < res->row; i++)
        ck_assert_int_eq(memcmp(&res->mat[i][res->row], &file_res->mat[i][file_res->col - 1], sizeof(double)), 1);
}

START(program_solved_equations)
{
    FILE *equation_mat = fopen("./func_tests/gauss_1.txt", "r");
    FILE *equation_res = fopen("./func_tests/res_gauss_1.txt", "r");

    ck_assert_ptr_nonnull(equation_mat);
    ck_assert_ptr_nonnull(equation_res);
    
    matrix *board = get_matrix_from_file(equation_mat);
    matrix *res = get_matrix_from_file(equation_res);

    ck_assert_ptr_nonnull(board);
    ck_assert_ptr_nonnull(res);
    
    int rc = gauss_solution(board);

    ck_assert_int_eq(rc, ok);
    ck_assert_mat_eq(board, res);

    close_if_opened_file(equation_mat);
    close_if_opened_file(equation_res);
    
    free_mat_if_not_null(board);
    free_mat_if_not_null(res);
}
END

START(equation_dont_have_solution)
{
    FILE *equation_mat = fopen("./func_tests/gauss_neg_2.txt", "r");

    ck_assert_ptr_nonnull(equation_mat);
    
    matrix *board = get_matrix_from_file(equation_mat);

    ck_assert_ptr_nonnull(board);
    
    int rc = gauss_solution(board);

    ck_assert_int_eq(rc, error);

    close_if_opened_file(equation_mat);
    free_mat_if_not_null(board);
}
END

START(equation_have_inifin_solution)
{
    FILE *equation_mat = fopen("./func_tests/gauss_neg_3.txt", "r");

    ck_assert_ptr_nonnull(equation_mat);
    
    matrix *board = get_matrix_from_file(equation_mat);

    ck_assert_ptr_nonnull(board);
    
    int rc = gauss_solution(board);

    ck_assert_int_eq(rc, error);

    close_if_opened_file(equation_mat);
    free_mat_if_not_null(board);
}
END

SUITE *gauss_unit_tests_suite(void)
{
    SUITE *s;
    TCASE *tc_pos;
    TCASE *tc_neg;

    s = suite_create("Hemogenous equations solving using gauss method");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, program_solved_equations);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, equation_dont_have_solution);
    tcase_add_test(tc_neg, equation_have_inifin_solution);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}
