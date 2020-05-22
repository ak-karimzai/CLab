#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MODE 1
#define NAME_FILE_IN 2
#define NAME_FILE_OUT 3
#define SUBSTRING 3
#define MAX_LEN_STR 100
#define MAX_QUANTITY_PROD 100
#define ERR_ARG 53

enum type_error
{
    ok,
    empty_err,
    fill_err,
    info_err,
};

typedef struct 
{
    char name[31];
    char manufacturer[16];
    int price;
    int quantity;
} product;

int my_strstr(char const *const str, char const *const str_sub, int len_sub)
{
    int len_str = 0;
    
    while (str[len_str])
        len_str++;
    if (len_str < len_sub)
        return FALSE;
    for (int i = len_sub - 1, j = len_str - 1; i >= 0; i--, j--)
    {
        if (str[j] != str_sub[i])
            return FALSE;
    }

    return TRUE;
}

int display_info(product arr[MAX_QUANTITY_PROD], char *substr, int len)
{
    int len_sub = 0;
    int flag = TRUE;

    while (substr[len_sub])
        len_sub++;

    for (int i = 0; i < len; i++)
    {
        if (my_strstr(arr[i].name, substr, len_sub))
        {
            printf("%s\n%s\n%d\n%d\n", arr[i].name, arr[i].manufacturer, arr[i].price, arr[i].quantity);
            flag = FALSE;
        }
    }
    return flag;
}

void write_file(FILE *f, product arr[MAX_QUANTITY_PROD], int len)
{
    fprintf(f, "%s\n%s\n%d\n%d", arr[0].name, arr[0].manufacturer, arr[0].price, arr[0].quantity);

    for (int j = 1; j < len; j++)
    {
        fprintf(f, "\n%s\n%s\n%d\n%d", arr[j].name, arr[j].manufacturer, arr[j].price, arr[j].quantity);
    }
}

void swap_struct(product arr[MAX_QUANTITY_PROD], int i, int j)
{
    product temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void sort_struct(product arr[MAX_QUANTITY_PROD], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j].price < arr[j + 1].price)
                swap_struct(arr, j, j + 1);
            else if (arr[j].price == arr[j + 1].price && arr[j].quantity < arr[j + 1].quantity)
                swap_struct(arr, j, j + 1);
        }
    }
}

int fill(FILE *f, product arr[MAX_QUANTITY_PROD])
{
    int i = 0;
    fseek(f, 0, SEEK_SET);

    while (TRUE)
    {
        if (feof(f))
            break;
        fgets(arr[i].name, 31, f);
        for (int j = 0; j < 31; j++)
            if (arr[i].name[j] == '\n')
            {
                arr[i].name[j] = '\0';
                break;
            }
        fgets(arr[i].manufacturer, 16, f);
        for (int j = 0; j < 16; j++)
            if (arr[i].manufacturer[j] == '\n')
            {
                arr[i].manufacturer[j] = '\0';
                break;
            }
        fscanf(f, "%d\n%d\n", &(arr[i].price), &(arr[i].quantity));
        i++;
    }

    return i;
}

int fill_new_info(product *new_info)
{
    fgets(new_info->name, 31, stdin);
    for (int i = 0; i < 31; i++)
        if (new_info->name[i] == '\n')
        {
            new_info->name[i] = '\0';
            break;
        }
    fgets(new_info->manufacturer, 16, stdin);
    for (int j = 0; j < 16; j++)
        if (new_info->manufacturer[j] == '\n')
        {
            new_info->manufacturer[j] = '\0';
            break;
        }
    
    int rc = scanf("%d\n%d", &(new_info->price), &(new_info->quantity));
    
    if (rc != 2)
        return fill_err;

    return ok;
}

void add_struct(product arr[MAX_QUANTITY_PROD], int len)
{
    int i = len - 1;

    while (i && arr[i - 1].price <= arr[i].price)
    {
        if (arr[i - 1].price == arr[i].price && arr[i - 1].quantity < arr[i].quantity)
            swap_struct(arr, i, i - 1);
        else if (arr[i - 1].price < arr[i].price)
            swap_struct(arr, i, i - 1);
        i--;
    }
}

int error_substr(char substr[MAX_LEN_STR])
{
    int i = 0;

    while (substr[i])
    {
        if (i > 31)
            return TRUE;
        i++;
    }

    return FALSE;
}

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