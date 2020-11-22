#ifndef _ADD_MUL_H
#define _ADD_MUL_H

#include <stdlib.h>

#include "data_structure.h"
#include "error_code.h"
#include "create_matrix.h"

matrix *addition(const matrix *lhs, const matrix *rhs);
matrix *multiplication(const matrix *lhs, const matrix *rhs);

#endif //_ADD_MUL_H