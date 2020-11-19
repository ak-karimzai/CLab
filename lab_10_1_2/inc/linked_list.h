#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdlib.h>
#include <string.h>
#include "data_struct.h"

int push(ll_polynome_t *polynome, node_t *node);

node_t *create_node(int coeff, int pow);

int create_list_from_line(char *str, ll_polynome_t *polynome);

int create_ll_node(ll_polynome_t **res_trict);

#endif //_LINKED_LIST_H_