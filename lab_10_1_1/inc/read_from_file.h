#ifndef _READ_FROM_FILE_H_
#define _READ_FROM_FILE_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_struct.h"
#include "free.h"

int product_init(product *pro, const char *name, int price);

node_t *get_node(void *data);

product *read_product(FILE *f);

node_t *create_node(FILE *input_file);

#endif //_READ_FROM_FILE_H_