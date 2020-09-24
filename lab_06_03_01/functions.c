#include "main.h"

int read_from_file(FILE *input, product *products, int *num_of_products)
{
    if (fscanf(input, "%d\n", num_of_products) == 1)
    {
        if (*num_of_products > ARRAY_MAX_SIZE || *num_of_products <= 0)
            return error;
    }
    else
        return error;
    
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
        if (fscanf(input, "%d\n", &products[i].price) != 1)
            return error;
    }
    return ok;
}

void display_to_screen(product *products, const int num_of_prod, const int price)
{
    for (int i = 0; i < num_of_prod; i++)
        if (products[i].price < price)
            fprintf(stdout, "%s\n%d\n", products[i].product_name, products[i].price);
}