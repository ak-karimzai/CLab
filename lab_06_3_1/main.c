#include <stdio.h>
#include <string.h>
#include "header.h"
// #include "readstructures.c"


int main(int argc, char **argv)
{
    FILE *input_file;
    product pro[15];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: app.exe FILE\n");
        return file_err;
    }

    input_file = fopen(argv[1], "r");

    if (!input_file || feof(input_file))
    {
        fprintf(stderr, "I/O error\n");
        return file_err;
    }

    int num_of_products;
    fscanf(input_file, "%d\n", &num_of_products);
    if (num_of_products > ARRAY_SIZE)
    {
        fprintf(stderr, "Incorrect input\n");
        return read_err;
    }

    // if (read_from_file(input_file, pro, num_of_products))
    //     return read_err;

    // puts("Enter your price:");
    // int user_price;
    // if (scanf("%d", &user_price) != 1)
    // {
    //     fprintf(stderr, "Uncorrect Input\n");
    //     return read_err;
    // }

    // print_to_screen(pro, num_of_products, user_price);
    return 0;
}