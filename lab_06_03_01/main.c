#include "main.h"
#include "functions.h"

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
    
    product products[ARRAY_MAX_SIZE];
    int p = atoi(argv[PRICE]);
    if (p <= 0)
        return error;

    int num_of_products;
    if (read_from_file(input_file, products, &num_of_products))
        return error;
    
    display_to_screen(products, num_of_products, p);
    fclose(input_file);
    return ok;
}