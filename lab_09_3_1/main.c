#include "./inc/main.h"

int main(int argc, char **argv)
{
    int rc = ok;
    if (argc == 3)
    {
        FILE *input_file = fopen(argv[FILE_NAME], "r");
        int p = atoi(argv[PRICE]);
        // printf("%d\n", p);
        if (input_file && p > 0)
        {
            int num_of_products;
            product *products = NULL;
            rc = read_from_file(input_file, &products, &num_of_products);
            if (rc == ok)
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
    // printf("%d\n", rc);
    return rc;
}