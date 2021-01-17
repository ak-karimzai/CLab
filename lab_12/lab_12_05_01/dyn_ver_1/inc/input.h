#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>

#include "error_code.h"

int file_count_objs(FILE *file);
int *read_objs_from_file(FILE *file, const int num_of_objs);
int *procees_data_from_file(FILE *input_file, int *num_of_objs);

#endif // INPUT_H