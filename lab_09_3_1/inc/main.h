#ifndef MAIN_H
#define MAIN_H

#define FILE_NAME 1
#define PRICE 2

#include "data_struct.h"

int read_from_file(FILE *f, product **prods, int *num_of_products);
void display_to_screen(product *products, const int num_of_elem);
int sort_by_price(product *products, const int num_of_elements, const int given_price);
void free_product_arr(product *products, const int num_of_objs);

#endif //MAIN_H