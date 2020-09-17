#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_SIZE 26
#define ARRAY_MAX_SIZE 15
#define FILE_NAME 1
#define PRICE 2

enum error_code
{
    ok,
    error
};

typedef struct
{
    char product_name[NAME_MAX_SIZE];
    int price;
} product;

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

int main(int argc, char **argv)
{
    if (argc != 3)
        return error;
    
    FILE *input_file = fopen(argv[FILE_NAME], "r");
    if (!input_file)
    {
        return error;
    }
    else if (feof(input_file))
    {
        return error;
    }
    else if (fgetc(input_file) == EOF)
    {
        return error;
    }
    else
    {
        rewind(input_file);
    }
    
    for (size_t i = 0; i < strlen(argv[PRICE]); i++)
        if (!(argv[PRICE][i] >= '0' && argv[PRICE][i] <= '9'))
            return error;

    product products[ARRAY_MAX_SIZE];
    int p = atoi(argv[PRICE]);
    if (!p)
        return error;
    
    int num_of_products;
    if (read_from_file(input_file, products, &num_of_products))
        return error;
    
    display_to_screen(products, num_of_products, p);
    fclose(input_file);
    return ok;
}