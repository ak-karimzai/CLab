#ifndef _MULTIPLICATION_UNIT_TEST_
#define _MULTIPLICATION_UNIT_TEST_

#include "../data_structure.h"

#define START START_TEST
#define END END_TEST
#define SUITE Suite
#define TCASE TCase
#define CKVER CK_VERBOSE

void close_if_opened_file(FILE *in);
void free_mat_if_not_null(matrix *mat);
matrix *get_matrix_from_file(FILE *input_file);
matrix *multiplication(const matrix *lhs, const matrix *rhs);

#endif //_MULTIPLICATION_UNIT_TEST_