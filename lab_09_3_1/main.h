#ifndef MAIN_H
#define MAIN_H

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

#endif //MAIN_H