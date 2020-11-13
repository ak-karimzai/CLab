#ifndef _CREATE_H_
#define _CREATE_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "push_pop.h"
#include "data_struct.h"

void init_list_node(poly_node **list);

string_t *get_line(void);

node_t *create_node(int m, int n);

int create_list_from_line(string_t *str, poly_node *list);

#endif //_CREATE_H_