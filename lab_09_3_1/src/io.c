#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "../inc/io.h"

void free_product_arr(product *products, const int num_of_objs)
{
    for (int i = 0; i < num_of_objs; i++)
        free(products[i].product_name);
    free(products);
}

int num_of_objs(FILE *input_file)
{
    int x;
    if (fscanf(input_file, "%d\n", &x) == 1 && x >= 0)
        return x;
    return 0;
}

void init_produnct_node(FILE *input_file, product *pro)
{
    size_t len;
    getline(&pro->product_name, &len, input_file);
    fscanf(input_file, "%d\n", &pro->price);
}

product *read_from_file(FILE *input_file, int *num_of_products)
{
    *num_of_products = num_of_objs(input_file);
    product *products = NULL;

    if (*num_of_products)
    {
        products = malloc(*num_of_products * sizeof(product));
        for (int i = 0; i < *num_of_products; i++)
            init_produnct_node(input_file, &products[i]);
    }
    return products;
}

void display_to_screen(product *products, const int num_of_elem)
{
    // printf("\n\n%d\n\n", num_of_elem);
    for (int i = 0; i < num_of_elem; i++)
        fprintf(stdout, "%s%d\n", products[i].product_name, products[i].price);
}