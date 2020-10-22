#ifndef _MAIN_H
#define _MAIN_H

#include "data_structure.h"
#include "error_code.h"

matrix *addition(const matrix *lhs, const matrix *rhs);
matrix *multiplication(const matrix *lhs, const matrix *rhs);
matrix *get_matrix_from_file(FILE *input_file);
void add_mat_to_file(const matrix *mat, FILE *output_file);
void add_solution_to_file(const matrix *mat, FILE *output);
void free_mat(matrix *mat);
int gauss_solution(matrix *mat);
void close_if_opened_file(FILE *in);

#endif //_MAIN_H