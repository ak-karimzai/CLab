#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void free_product_arr(product *products, const int num_of_objs)
{
    for (int i = 0; i < num_of_objs; i++)
        free(products[i].product_name);
    free(products);
}

int num_of_objs(FILE *input_file)
{
    char *line = NULL;
    ssize_t read;
    size_t len;
    int x, count = 0;
    while ((read = getline(&line, &len, input_file)) != -1 && \
                       fscanf(input_file, "%d\n", &x) == 1)
        count++;
    
    free(line);
    if (!(feof(input_file) || fgetc(input_file) == EOF))
        return 0;
    rewind(input_file);
    return count;
}

product *read_from_file(FILE *input, int *num_of_products)
{
    int rc = ok;
    *num_of_products = num_of_objs(input);
    product *products = NULL;
    if (*num_of_products == 0)
        rc = error;
    else
    {
        products = calloc(*num_of_products, sizeof(product));
        if (!products)
            rc = error;
        else
        {
            for (int i = 0; i < *num_of_products; i++)
            {
                ssize_t read;
                size_t len;
                if (!((read = getline(&products[i].product_name, &len, input)) != -1 && \
                    fscanf(input, "%d\n", &products[i].price) == 1 && products[i].price >= 0))
                {
                    rc = error;
                    break;
                }
                // printf("%s\n%d\n", products[i].product_name, products[i].price);
            }
        }
    }
    if (rc != ok)
    {
        free_product_arr(products, *num_of_products);
        return NULL;
    }
    return products;
}

void display_to_screen(product *products, const int num_of_elem)
{
    printf("\n\n%d\n\n", num_of_elem);
    for (int i = 0; i < num_of_elem; i++)
        fprintf(stdout, "%s%d\n", products[i].product_name, products[i].price);
}