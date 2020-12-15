#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int read_from_file(FILE *input, product *products, int *num_of_products);
void display_to_screen(product *products, const int num_of_elem);
int sort_by_price(product *products, const int num_of_elements, const int given_price);

#endif // FUNCTIONS_H