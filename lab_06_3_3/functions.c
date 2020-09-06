#include <stdio.h>

#define ARRAY_SIZE 15
#define PRODUCT_NAME_MAX_SIZE 25

typedef struct 
{
    char product_name[PRODUCT_NAME_MAX_SIZE + 1];
    int price;
} product;

typedef enum 
{
    ok,
    read_err,
    file_err
} error_type;

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

error_type read_from_file(FILE *is, product *products, const int n)
{
    for (int i = 0; i < n; i++)
    { 
        fgets(products[i].product_name, (PRODUCT_NAME_MAX_SIZE + 1), is);
        // printf("%d\n", strlen(products[i].product_name));
        // products[i].product_name[PRODUCT_NAME_MAX_SIZE] != '\n' ? printf("%c\n", 'y') : printf("%c\n", 'a');
        // int flag = 0;
        for (int j = 0; j < PRODUCT_NAME_MAX_SIZE + 1; j++)
        {
            if (products[i].product_name[j] == '\n')
            {
                products[i].product_name[j] = '\0';
                // flag = 1;
                break;
            }
        }
        // if (!flag)
        // {
        //     fprintf(stderr, "Product name must be upto 25 symbols.\n");
        //     return read_err;
        // }
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