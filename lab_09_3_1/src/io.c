#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "../inc/io.h"

void free_product_arr(product *products, const int num_of_objs)
{
    for (int i = 0; i < num_of_objs; i++)
        if (products[i].product_name)
            free(products[i].product_name);
    free(products);
}

void init_produnct_node(FILE *input_file, product *pro)
{
    size_t len;
    getline(&pro->product_name, &len, input_file);
    fscanf(input_file, "%d\n", &pro->price);
}

product *read_from_file(FILE *input_file, int *num_of_products)
{
    product *products = NULL;
    if (fscanf(input_file, "%d\n", num_of_products) == 1 && *num_of_products > 0)
    {
        if (*num_of_products)
        {
            products = malloc(*num_of_products * sizeof(product));
            if (products)
            {
                for (int i = 0; i < *num_of_products; i++)
                {
                    init_produnct_node(input_file, &products[i]);
                    if (products[i].price <= 0)
                    {
                        free_product_arr(products, *num_of_products);
                        return NULL;
                    }
                }
            }
        }
    }
    else
        return NULL;
    return products;
}

void display_to_screen(product *products, const int num_of_elem)
{
    // printf("\n\n%d\n\n", num_of_elem);
    for (int i = 0; i < num_of_elem; i++)
        fprintf(stdout, "%s%d\n", products[i].product_name, products[i].price);
}