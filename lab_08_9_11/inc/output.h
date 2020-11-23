#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <stdio.h>
#include <stdlib.h>

#include "data_structure.h"

void add_solution_to_file(const matrix *mat, FILE *output);
void add_mat_to_file(const matrix *mat, FILE *output_file);

#endif //_OUTPUT_H