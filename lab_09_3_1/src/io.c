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

product *read_from_file(FILE *input_file, int *num_of_products)
{
    int rc = ok;
    product *products = NULL;
    if (fscanf(input_file, "%d\n", num_of_products) != 1 || *num_of_products <= 0)
        rc = error;
    else
    {
        products = malloc(*num_of_products * sizeof(product));
        if (products == NULL)
            rc = error;
        else
        {
            for (int i = 0; i < *num_of_products; i++)
            {
                size_t len;
                ssize_t read = getline(&products[i].product_name, &len, input_file);
                if (read == -1 || fscanf(input_file, "%d\n", &products[i].price) != 1 || products[i].price <= 0)
                {
                    free_product_arr(products, *num_of_products);
                    rc = error;
                    break;
                }
            }
        }
    }
    return rc == ok ? products : NULL;
}

void display_to_screen(product *products, const int num_of_elem)
{
    // printf("\n\n%d\n\n", num_of_elem);
    for (int i = 0; i < num_of_elem; i++)
        fprintf(stdout, "%s%d\n", products[i].product_name, products[i].price);
}