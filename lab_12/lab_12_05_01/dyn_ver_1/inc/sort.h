#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <stdlib.h>

#ifndef LIB_DLL
#ifdef IMPORT
#define LIB_DLL __declspec(dllexport)
#else
#define LIB_DLL __declspec(dllexport)
#endif
#endif

#define DLL_DECL __cdecl

typedef int (*compare)(const void *lhs, const void *rhs);
LIB_DLL int DLL_DECL compare_int(const void *lhs, const void *rhs);
LIB_DLL void DLL_DECL mysort(void *arr_lhs, size_t num_of_elements, const size_t size, compare comp);

#endif // SORT_H