#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int read_from_file(FILE *input, product *products, int *num_of_products)
{
    int rc = ok;
    if (fscanf(input, "%d\n", num_of_products) != 1)
        rc = error;
    else
    {
        if (*num_of_products > ARRAY_MAX_SIZE || *num_of_products <= 0)
            return error;
        else
        {
            for (int i = 0; i < *num_of_products; i++)
            {
                fgets(products[i].product_name, NAME_MAX_SIZE, input);
                for (int j = 0; j < NAME_MAX_SIZE; j++)
                {
                    if (products[i].product_name[j] == '\n')
                    {
                        products[i].product_name[j] = '\0';
                        break;
                    }
                }
                if (fscanf(input, "%d\n", &products[i].price) != 1 || products[i].price <= 0)
                {
                    rc = error;
                    break;
                }
            }
        }
    }
    return rc;
}

void display_to_screen(product *products, const int num_of_elem)
{
    for (int i = 0; i < num_of_elem; i++)
        fprintf(stdout, "%s\n%d\n", products[i].product_name, products[i].price);
}