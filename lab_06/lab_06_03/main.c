#include <stdio.h>

#define ARRAY_SIZE 15
#define PRODUCT_NAME_MAX_SIZE 25

typedef struct 
{
    char product_name[PRODUCT_NAME_MAX_SIZE + 1];
    int price;
} product;

enum error_type 
{
    ok,
    read_err,
    file_err
};

void swap(product *x, product *y)
{
    product temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(product *products, const int size_of_arr)
{
    for (int i = 0; i < size_of_arr - 1; i++)
        for (int j = 0; j < size_of_arr - 1 - i; j++)
            if (products[j].price > products[j + 1].price)
                swap(&products[j], &products[j + 1]);
}

int read_from_file(FILE *is, product *products, const int n)
{
    for (int i = 0; i < n; i++)
    { 
        fgets(products[i].product_name, PRODUCT_NAME_MAX_SIZE + 1, is);
        for (int j = 0; j < PRODUCT_NAME_MAX_SIZE + 1; j++)
        {
            if (products[i].product_name[j] == '\n')
            {
                products[i].product_name[j] = '\0';
                break;
            }
            else if (j == PRODUCT_NAME_MAX_SIZE)
            {
                fprintf(stderr, "Product name must be upto 25 symbols.\n");
                return read_err;
            }
        }
        fscanf(is, "%d\n", &products[i].price);
    }
    bubble_sort(products, n);
    return ok;
}

void print_to_screen(const product *products, const int n, const int user_price)
{
    for (int i = 0; i < n; i++)
    {
        if (products[i].price < user_price)
            printf("%s\n%d\n", products[i].product_name, products[i].price);
        else
            break;
    }
}

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

    if (read_from_file(input_file, pro, num_of_products))
        return read_err;

    puts("Enter your price:");
    int user_price;
    if (scanf("%d", &user_price) != 1)
    {
        fprintf(stderr, "Uncorrect Input\n");
        return read_err;
    }

    print_to_screen(pro, num_of_products, user_price);
    return 0;
}