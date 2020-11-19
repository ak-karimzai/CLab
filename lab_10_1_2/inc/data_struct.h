#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

enum error_code
{
    ok,
    error
};

enum print_flags
{
    derivative,
    just_print,
    sum_print
};

typedef struct node
{
    int coeff;
    int pow;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *end;
} ll_polynome_t;

#define POLYNOM_VALUE "val"
#define POLYNOM_DERIVATIVE "ddx"
#define POLYNOM_ADDITION "sum"
#define POLYNOM_DIVISION "dvd"

#endif  //_DATA_STRUCT_H_