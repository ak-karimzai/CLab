#ifndef _FREE_H
#define _FREE_H

#include <stdio.h>
#include <stdlib.h>
#include "data_structure.h"

void close_if_opened_file(FILE *in);
void free_mat_if_not_null(matrix *mat);
void free_mat(matrix *mat);

#endif //_FREE_H