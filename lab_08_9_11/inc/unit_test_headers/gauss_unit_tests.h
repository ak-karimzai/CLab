#ifndef _GAUSS_UNIT_TESTS_H_
#define _GAUSS_UNIT_TESTS_H_

#define START START_TEST
#define END END_TEST
#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

#include "../data_structure.h"
#include "../error_code.h"
void close_if_opened_file(FILE *in);
void free_mat_if_not_null(matrix *mat);
int gauss_solution(matrix *mat);
matrix *get_matrix_from_file(FILE *input_file);

#endif //_GAUSS_UNIT_TESTS_H_