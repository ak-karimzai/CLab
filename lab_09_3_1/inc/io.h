#ifndef IO_H
#define IO_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_struct.h"

int read_from_file(FILE *f, product **prods, int *num_of_products);
void display_to_screen(product *products, const size_t num_of_elem);
void free_product_arr(product *products, const size_t num_of_objs);

#endif // IO_H