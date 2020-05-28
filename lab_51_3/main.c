#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv)
{
    FILE *in;

    if (argc < 3) 
        return arg_err;
    
    if (strcmp(argv[1], "c") == ok)
    {
        int n = atoi(argv[2]);
        if (n == 0)
            return get_err;
        
        in = fopen(argv[3], "wb");
        
        if (in == NULL)
            return file_err;

        add_to_file(in, n);

        fclose(in);
        return ok;
    }

    if (strcmp(argv[1], "p") == 0)
    {
        in = fopen(argv[2], "rb");
        
        if (in == NULL)
            return file_err;

        int n = file_size(in);
        
        if (n == 0)
            return empty_file;

        display(in, n);

        fclose(in);
        
        return ok;
    }
    
    if (strcmp(argv[1], "s") == 0)
    {
        in = fopen(argv[2], "rb+");
        
        int n = file_size(in);

        if (n == 0)
            return empty_file;
        
        if (sort_file(in, n))
            return put_err;

        return ok;
    }
}