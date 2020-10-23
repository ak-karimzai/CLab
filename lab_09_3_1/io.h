#ifndef IO_H
#define IO_H

#define FILE_NAME 1
#define PRICE 2

enum error_code
{
    ok,
    error
};

typedef struct
{
    char *product_name;
    int price;
} product;

#endif // IO_H