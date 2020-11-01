#ifndef _HEAD_UNIT_H_
#define _HEAD_UNIT_H_

#include "../data_struct.h"
int read_from_file(FILE *f, product **prods, int *num_of_products);
void free_product_arr(product *products, const int num_of_products);

#endif //_HEAD_UNIT_H_