#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_SIZE 26
#define ARRAY_MAX_SIZE 15

enum error_code
{
    ok,
    file_err,
    read_err,
    arg_err
};

typedef struct
{
    char product_name[NAME_MAX_SIZE];
    int price;
} product;

int read_from_file(FILE *f, product *pro, int *n)
{
    int rc = ok;
    for (int i = 0; i < *n; i++)
    {
        fgets(pro[i].product_name, NAME_MAX_SIZE, f);
        for (int j = 0; j < NAME_MAX_SIZE; j++)
        {
            if (pro[i].product_name[j] == '\n')
            {
                pro[i].product_name[j] = '\0';
                break;
            }
        }

        if (fscanf(f, "%d\n", &pro[i].price) != 1)
            rc = read_err;    
    }
    return rc;
}

void print_to_screen(const product *pro, const int *n, const int *p)
{
    for (int i = 0; i < *n; i++)
    {
        if (pro[i].price < *p)
            fprintf(stdout, "%s\n%d\n", pro[i].product_name, pro[i].price);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: app.exe FILE price\n");
        return arg_err;
    }

    FILE *input_file;
    product pro[ARRAY_MAX_SIZE];
    int p = atoi(argv[2]);
    if (p == 0)
        return read_err;
    //printf("%d\n", p);

    input_file = fopen(argv[1], "r");
    if (!input_file || feof(input_file))
    {
        fprintf(stderr, "I/O error\n");
        return file_err;
    }

    int num_of_products;
    fscanf(input_file, "%d\n", &num_of_products);
    if (num_of_products > ARRAY_MAX_SIZE || num_of_products <= 0)
    {
        fprintf(stderr, "Incorrect input\n");
        return read_err;
    }

    if (read_from_file(input_file, pro, &num_of_products)) 
    {
        // fprintf(stderr, "Problem in reading\n");
        return read_err;
    }

    print_to_screen(pro, &num_of_products, &p);
    return ok;
}