#ifndef _FREE_H_
#define _FREE_H_

#include <stdlib.h>
#include "data_struct.h"

void free_node_c(node_t *node);

void free_list(node_t *head);

void free_prod(product *prod);

void free_node(node_t *node);

void free_elements(node_t **head);

#endif //_FREE_H_