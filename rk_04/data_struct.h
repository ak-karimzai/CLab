#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

enum error_type
{
    ok,
    error
};

typedef struct node
{
    char *name;
    int age;
    struct node *mark;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *end;
} linked_list;

#endif //_DATA_STRUCT_H_