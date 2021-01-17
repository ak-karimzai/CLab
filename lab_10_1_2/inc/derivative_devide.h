#ifndef _DERIVATIVE_DEVIDE_H_
#define _DERIVATIVE_DEVIDE_H_

#include <stdlib.h>

#include "data_struct.h"
#include "linked_list.h"

void derivative_of_polynome(ll_polynome_t *polynome);

void devide_pol_to_odd_even(ll_polynome_t *polynome, ll_polynome_t *odd_nodes, ll_polynome_t *even_nodes);

#endif //_DERIVATIVE_DEVIDE_H_