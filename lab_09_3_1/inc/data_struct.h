#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

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

#endif //_DATA_STRUCT_H_