#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv)
{
    if (argc != 4 && argc != 3)
        return ERR_ARG;
    
    if (strcmp(argv[1], "st") == ok)
    {
        if (argc != 4)
            return ERR_ARG;
        
        FILE *f = fopen(argv[2], "r");
        if (!f)
            return fill_err;
        
        if (getc(f) == EOF)
        {
            fclose(f);
            return empty_err;
        }
        product arr[MAX_QUANTITY_PROD];
        int len = fill(f, arr);

        if (len <= 0)
        {
            fclose(f);
            return fill_err;
        }
        FILE *f_out = fopen(argv[3], "w");
        if (!f_out)
        {
            fclose(f);
            return fill_err;
        }

        sort_struct(arr, len);
        write_file(f_out, arr, len);
        fclose(f_out);
        fclose(f);
    }
    else if (strcmp(argv[1], "ft") == ok)
    {
        if (argc != 4)
            return ERR_ARG;
        
        FILE *f = fopen(argv[2], "r");

        if (!f)
            return fill_err;
        
        if (getc(f) == EOF)
        {
            fclose(f);
            return empty_err;
        }

        product arr[MAX_QUANTITY_PROD];
        int len = fill(f, arr);

        if (len <= 0)
        {
            fclose(f);
            return fill_err;
        }
        char substr[MAX_LEN_STR];
        strcpy(substr, argv[3]);

        if (error_substr(substr))
        {
            fclose(f);
            return info_err;
        }

        if (display_info(arr, substr, len))
        {
            fclose(f);
            return info_err;
        }
        fclose(f);
    }
    else if (strcmp(argv[1], "at") == ok)
    {
        if (argc != 3)
            return ERR_ARG;
        
        FILE *f = fopen(argv[2], "r");
        if (!f)
            return fill_err;
        
        if (getc(f) == EOF)
        {
            fclose(f);
            return empty_err;
        }

        product arr[MAX_QUANTITY_PROD];
        int len = fill(f, arr);
        if (len <= 0)
        {
            fclose(f);
            return fill_err;
        }
        product new_info;
        fclose(f);
        if (fill_new_info(&new_info) != ok)
            return info_err;
        
        arr[len++] = new_info;
        f = fopen(argv[2], "w");
        add_struct(arr, len);
        write_file(f, arr, len);
        fclose(f);
    }
    else
        return ERR_ARG;
    
    return ok;
}