#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

typedef struct
{
    char *product_name;
    int price;
} product;

typedef struct node node_t;

struct node
{
    product *data;
    node_t *next;
};

enum error_code
{
    ok,
    error
};

typedef int (*comparator)(const void*, const void*);

#endif //_DATA_STRUCT_H_