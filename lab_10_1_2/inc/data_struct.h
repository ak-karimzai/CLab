#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

typedef struct
{
    int m;
    int n;
} polynom_t;

typedef struct node
{
    polynom_t data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *end;
} poly_node;

typedef struct 
{
    char *string;
    size_t len;
} string_t;

enum error_code
{
    ok,
    error
};

#endif //_DATA_STRUCT_H_