#ifndef _POLYNOM_SUM_H_
#define _POLYNOM_SUM_H_

#include <stdio.h>
#include <stdlib.h>

#include "data_struct.h"
#include "create.h"
#include "free.h"

int create_linked_list(string_t *first_poly, string_t *second_poly, poly_node *lhs, poly_node *rhs);

void print_sum_of_polys(poly_node *list);

poly_node *sum_of_polys(poly_node *lhs, poly_node *rhs);

#endif //_POLYNOM_SUM_H_