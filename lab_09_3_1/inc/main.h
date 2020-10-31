#ifndef MAIN_H
#define MAIN_H

#define FILE_NAME 1
#define PRICE 2

#include "data_struct.h"

product *read_from_file(FILE *input, int *num_of_products);
void display_to_screen(product *products, const int num_of_elem);
int sort_by_price(product *products, const int num_of_elements, const float given_price);
void free_product_arr(product *products, const int num_of_objs);

#endif //MAIN_H