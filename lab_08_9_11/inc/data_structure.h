#ifndef _DATA_STRUCTURE_H
#define _DATA_STRUCTURE_H

typedef struct
{
    int row;
    int col;
    double val;
} coordinate_data;

typedef struct 
{
    int row;
    int col;
    double **mat;
} matrix;

#endif //_DATA_STRUCTURE_H