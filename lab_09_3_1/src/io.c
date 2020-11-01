// #define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/io.h"

int product_init(product *pro, const char *name, int price)
{
    char *tmp = strdup(name);
    
    if (tmp)
    {
        free(pro->product_name);

        pro->product_name = tmp;
        pro->price = price;

        return ok;
    }

    return error;
}

int read_product(FILE *f, product *prod)
{
    char *buf = NULL;
    size_t len = 0;
    ssize_t read;
    int price;
    int rc = error;

    if ((read = getline(&buf, &len, f)) > 0)
    {
        if (fscanf(f, "%d\n", &price) == 1)
        {
            if (price > 0)
                rc = product_init(prod, buf, price);
            else
                rc = error;
        }
        else
            rc = error;
    }
    else
        rc = error;

    free(buf);

    return rc;
}

int product_read(FILE *f, product *prod, int n)
{
    int rc = ok;
    
    for (int i = 0; rc == ok && i < n; i++)
        rc = read_product(f, prod + i);

    return rc;
}

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

int read_from_file(FILE *f, product **prods, int *num_of_products)
{
    product *ptmp;
    int n;
    int rc;

    *prods = NULL;
    *num_of_products = 0;

    if (fscanf(f, "%d\n", &n) == 1 && n > 0)
    {
        ptmp = calloc(n, sizeof(product));
        if (ptmp)
        {   
            rc = product_read(f, ptmp, n);

            if (rc == ok)
            {
               *prods = ptmp;
               *num_of_products = n;
            }
            else
               free_product_arr(ptmp, n);
        }
        else
            rc = error;
    }
    else
        rc = error;

    return rc;
}

void display_to_screen(product *products, const int num_of_elem)
{
    for (int i = 0; i < num_of_elem; i++)
    {
        // if (products[i].product_name[strlen(products[i].product_name) - 1] == '\n')
        fprintf(stdout, "%s%d\n", products[i].product_name, products[i].price);
    }
}