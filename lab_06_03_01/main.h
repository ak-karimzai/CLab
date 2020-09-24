#include <stdio.h>
#include <stdlib.h>

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
