#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "functions.h"

int main(int argc, char **argv)
{
    int rc = ok;
    product *products = NULL;

    if (argc == 3)
    {
        FILE *input_file = fopen(argv[FILE_NAME], "r");
        if (!input_file)
            rc = error;
        else
        {
            int p = atoi(argv[PRICE]);
            if (p <= 0)
                rc = error;
            else
            {
                int num_of_products;
                products = read_from_file(input_file, &num_of_products);
                if (products == NULL)
                    rc = error;
                else
                {
                    int printable_elements = sort_by_price(products, num_of_products, p);
                    display_to_screen(products, printable_elements);
                    free_product_arr(products, num_of_products);
                }
                // printf("%d\n", rc);
            }
            fclose(input_file);
        }
    }
    else
        rc = error;
    // printf("%d\n", rc);
    return rc;
}