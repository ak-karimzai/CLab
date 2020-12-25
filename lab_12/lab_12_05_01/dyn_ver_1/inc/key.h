#ifndef KEY_H
#define KEY_H

#include <stdlib.h>
#include "error_code.h"

#ifndef LIB_DLL
#ifdef IMPORT
#define LIB_DLL __declspec(dllimport)
#else
#define LIB_DLL __declspec(dllexport)
#endif
#endif

#define DLL_DECL __cdecl

LIB_DLL int DLL_DECL key(const int *pb_src, const int src_size, int *pb_dst, int *prd_size);

#endif // KEY_H