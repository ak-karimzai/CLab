#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "functions.h"

int main(int argc, char **argv)
{
    int rc = ok;
    product products[ARRAY_MAX_SIZE];

    if (argc != 3)
        rc = error;
    else
    {
        FILE *input_file = fopen(argv[FILE_NAME], "r");
        if (!input_file || feof(input_file) || fgetc(input_file) == EOF)
        {
            rc = error;
        }
        else
        {
            rewind(input_file);
            int p = atoi(argv[PRICE]);
            if (p <= 0)
                return error;
            else
            {
                int num_of_products;
                if (read_from_file(input_file, products, &num_of_products) != ok)
                    rc = error;
                else
                {
                    int printable_elements = sort_by_price(products, num_of_products, p);
                    display_to_screen(products, printable_elements);
                }
            }
            fclose(input_file);
        }
    }
    return rc;
}