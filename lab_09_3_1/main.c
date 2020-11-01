#include <stdio.h>
#include <stdlib.h>
#include "./inc/main.h"

int main(int argc, char **argv)
{
    int rc = ok;
    if (argc == 3)
    {
        FILE *input_file = fopen(argv[FILE_NAME], "r");
        int p = atoi(argv[PRICE]);
        if (input_file && p > 0)
        {
            int num_of_products;
            product *products = read_from_file(input_file, &num_of_products);
            if (products)
            {
                int printable_eles = sort_by_price(products, num_of_products, p);
                display_to_screen(products, printable_eles);
                free_product_arr(products, num_of_products);
            }
            else
                rc = error;
            fclose(input_file);
        }
        else
        {
            if (input_file)
                fclose(input_file);
            rc = error;
        }
    }
    else
        rc = error;
    return rc;
}