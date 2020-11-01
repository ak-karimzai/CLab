#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "../inc/io.h"

void free_product_arr(product *products, const int num_of_products)
{
    if (products)
    {
        for (int i = 0; i < num_of_products; i++)
            if (products[i].product_name)
                free(products[i].product_name);
        free(products);
    }
}

product *read_from_file(FILE *input, int *num_of_products)
{
    int rc = ok;
    size_t len;
    product *products = NULL;
    if (fscanf(input, "%d\n", num_of_products) != 1 || *num_of_products <= 0)
        rc = error;
    else
    {
        products = malloc(*num_of_products * sizeof(product));
        if (products)
        {
            for (int i = 0; i < *num_of_products; i++)
            {
                getline(&products[i].product_name, &len, input);
                if (fscanf(input, "%d\n", &products[i].price) != 1 || products[i].price <= 0)
                {
                    rc = error;
                    break;
                }
            }
            if (!(feof(input) || fgetc(input) == EOF))
                rc = error;
        }
        else
            rc = error;
    }
    if (rc == error)
        free_product_arr(products, *num_of_products);
    return rc == ok ? products : NULL;
}

void display_to_screen(product *products, const int num_of_elem)
{
    for (int i = 0; i < num_of_elem; i++)
        fprintf(stdout, "%s%d\n", products[i].product_name, products[i].price);
}