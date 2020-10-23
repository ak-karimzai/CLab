#ifndef FUNCTIONS_H
#define FUNCTIONS_H

product *read_from_file(FILE *input, int *num_of_products);
void display_to_screen(product *products, const int num_of_elem);
int sort_by_price(product *products, const int num_of_elements, const int given_price);
void free_product_arr(product *products, const int num_of_objs);

#endif // FUNCTIONS_H