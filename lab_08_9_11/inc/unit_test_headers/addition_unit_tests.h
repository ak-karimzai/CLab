#ifndef _ADDITION_UNIT_TESTS_H
#define _ADDITION_UNIT_TESTS_H

#include "../data_structure.h"

#define START START_TEST
#define END END_TEST
#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

void close_if_opened_file(FILE *in);
void free_mat_if_not_null(matrix *mat);
matrix *addition(const matrix *lhs, const matrix *rhs);
matrix *get_matrix_from_file(FILE *input_file);

#endif //_ADDITION_UNIT_TESTS_H