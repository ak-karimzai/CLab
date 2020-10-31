#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "../inc/io.h"

void free_product_arr(product *products, const unsigned int num_of_objs)
{
    for (size_t i = 0; i < num_of_objs; i++)
        if (products[i].product_name)
            free(products[i].product_name);
    free(products);
}

unsigned int read_unsigned_int(FILE *input_file)
{
    int x;
    if (fscanf(input_file, "%d\n", &x) == 1 && x > 0)
        return (unsigned int)(x);
    return 0; 
}

char *get_line(FILE *input_file)
{
    size_t len;
    char *line = NULL;
    ssize_t read = getline(&line, &len, input_file);
    if (read < 0)
    {
        free(line);
        return NULL;
    }
    return line;
}

product *read_from_file(FILE *input_file, unsigned int *num_of_products)
{
    *num_of_products = read_unsigned_int(input_file);
    product *products = NULL;

    if (*num_of_products)
    {
        products = malloc(*num_of_products * sizeof(product));
        for (int i = 0; i < *num_of_products; i++)
        {
            products[i].product_name = get_line(input_file);
            products[i].price = read_unsigned_int(input_file);
            if (products[i].product_name == NULL || products[i].price == 0)
            {
                free_product_arr(products, *num_of_products);
                return NULL;
            }
        }
    }
    return products;
}

void display_to_screen(product *products, const unsigned int num_of_elem)
{
    // printf("\n\n%d\n\n", num_of_elem);
    for (size_t i = 0; i < num_of_elem; i++)
        fprintf(stdout, "%s%d\n", products[i].product_name, products[i].price);
}