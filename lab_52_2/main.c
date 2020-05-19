#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define NAME_SIZE 31
#define MANUF_SIZE 16
#define COUNT_WRITE 1
#define COUNT_READED 1
#define MIN_ARGS 3
#define FILE_NAME 2
#define KEY_ARGS 1
#define N 100
#define M 4
#define ARGS_ERR 53

#define TRUE 1
#define FALSE 0

enum type_error
{
    ok,
    file_err,
    input_err,
    get_err,
    put_err,
    empty_file,
    no_substr
};

typedef struct
{
    char name[NAME_SIZE];
    char manafacturer[MANUF_SIZE];
    uint32_t price;
    uint32_t count;
} product_t;

int size_counter(FILE *const f)
{    
    fseek(f, 0, SEEK_END);
    int size = ftell(f) / sizeof(product_t);
    fseek(f, 0, SEEK_SET);

    return size;
}

int get_by_pos(FILE *const f, const int pos, product_t *const product_list)
{
    fseek(f, pos * sizeof((*product_list)) - sizeof((*product_list)), SEEK_SET);
    if (fread(product_list, sizeof((*product_list)), COUNT_READED, f) != COUNT_READED)
    {
        return get_err;
    }
    return ok;
}

int put_by_pos(FILE *const f, const int pos, const product_t product_list)
{
    fseek(f, pos * sizeof(product_list) - sizeof(product_list), SEEK_SET);
    if (fwrite(&product_list, sizeof(product_list), COUNT_WRITE, f) != COUNT_WRITE)
    {
        return put_err;
    }
    return ok;
}

int copy_file(FILE *const f1, FILE *const f2)
{
    product_t product;
    int size = size_counter(f1);

    for (int i = 1; i <= size; i++)
    {
        if (get_by_pos(f1, i, &product) != ok)
        {
            return get_err;
        }
        if (put_by_pos(f2, i, product) != ok)
        {
            return put_err;
        }
    }

    return ok;
}

int sort_file(FILE *const f)
{
    product_t pr1, pr2, temp;
    const int size = size_counter(f);

    for (int i = 1; i < size; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j <= size; j++)
        {
            if (get_by_pos(f, j, &pr1) != ok)
            {
                return get_err;
            }
            if (get_by_pos(f, min_ind, &pr2) != ok)
            {
                return get_err;
            }

            if (pr1.price > pr2.price)
            {
                min_ind = j;
            }
            if (pr1.price == pr2.price)
            {
                if (pr1.count > pr2.count)
                {
                    min_ind = j;
                }
            }
        }
        if (get_by_pos(f, i, &temp) != ok)
        {
            return get_err;
        }
        if (get_by_pos(f, min_ind, &pr1) != ok)
        {
            return get_err;
        }

        if (put_by_pos(f, i, pr1) != ok)
        {
            return put_err;
        }
        if (put_by_pos(f, min_ind, temp) != ok)
        {
            return put_err;
        }
    }

    return ok;
}

int check_substr(const char *const name, const char *const substr)
{
    int len_name = strlen(name) - 1;
    int len_substr = strlen(substr) - 1;
    
    while (len_substr >= 0)
    {
        if (name[len_name] != substr[len_substr])
        {
            return FALSE;
        }
        --len_substr;
        --len_name;
    }

    return TRUE;
}


void printstruct(const product_t product)
{
    printf("%s\n", product.name);
    printf("%s\n", product.manafacturer);
    printf("%u\n", product.price);
    printf("%u\n", product.count);
}

void print_file(FILE *const f)
{
    product_t temp_struct;
    fseek(f, 0, SEEK_SET);
    while (fread(&temp_struct, sizeof(temp_struct), 1, f))
    {
        printstruct(temp_struct);
    }
}

int info_items(FILE *const f, const char *const substr)
{
    product_t product;
    int count = 0;
    const int size = size_counter(f);

    for (int i = 1; i <= size; i++) 
    {
        if (get_by_pos(f, i, &product) != ok)
        {
            return get_err;
        }

        if (check_substr(product.name, substr))
        {
            ++count;
            printstruct(product);
        }
    }

    if (0 == count)
    {
        return no_substr;
    }

    return ok;
}

int add_info(FILE *const f, const product_t temp)
{
    product_t prod;
    const int size = size_counter(f);
    int pos = 1;

    for (int i = 1; i <= size; i++)
    {
        if (get_by_pos(f, i, &prod) != ok)
        {
            return get_err;
        }

        if ((temp.price == prod.price && temp.count > prod.count) || (temp.price > prod.price))
        {
            break;
        }
        ++pos;
    }
    
    for (int i = size; i >= pos; i--)
    {
        if (get_by_pos(f, i, &prod) != ok)
        {
            return get_err;
        }
        if (put_by_pos(f, (i + 1), prod) != ok)
        {
            return put_err;
        }
    }

    if (put_by_pos(f, pos, temp) != ok)
    {
        return put_err;
    }
    
    return ok;
}

int enter_structure(FILE *const f)
{
    product_t temp_struct;
    memset(&temp_struct, 0, sizeof(product_t));
    puts("Enter name: ");
    if (scanf("%s", temp_struct.name) != COUNT_READED)
    {
        return input_err;
    }
    puts("Enter manafacturer: ");
    if (scanf("%s", temp_struct.manafacturer) != COUNT_READED)
    {
        return input_err;
    }
    puts("Enter price: ");
    if (scanf("%u", &temp_struct.price) != COUNT_READED)
    {
        return input_err;
    }
    puts("Enter count: ");
    if (scanf("%u", &temp_struct.count) != COUNT_READED)
    {
        return input_err;
    }

    int code_err = add_info(f, temp_struct);
    if (code_err != ok)
    {
        return code_err;
    }

    return ok;
}

int check_size(FILE *const f)
{
    const int size = size_counter(f);
    if (0 == size)
    {
        puts("File is empty");
        return empty_file;
    }
    return ok;
}

int main(const int argc, const char *const argv[])
{
    setbuf(stdout, NULL);
    FILE *f; 

    if (argc < MIN_ARGS)
    {
        puts("Invalid args!");
        return ARGS_ERR;
    }

    if (!strcmp(argv[KEY_ARGS], "sb"))
    {
        FILE *f1;
        if (argc < MIN_ARGS + 1 || argv[FILE_NAME + 1] == NULL)
        {
            puts("Invalid args!");
            return ARGS_ERR;
        }
        if ((f1 = fopen(argv[FILE_NAME + 1], "w+b")) == NULL || (f = fopen(argv[FILE_NAME], "rb")) == NULL)
        {
            puts("Cant open file");
            return file_err;
        }
        if (check_size(f))
        {
            fclose(f);
            return empty_file;
        }

        int code_err = copy_file(f, f1);
        if (code_err != ok)
        {
            fclose(f);
            fclose(f1);
            return code_err;
        }
        code_err = sort_file(f1);
        if (code_err != ok)
        {
            fclose(f);
            fclose(f1);
            return code_err;
        }

        print_file(f1);
        fclose(f);
        fclose(f1);

        return ok;
    }

    if (!strcmp(argv[KEY_ARGS], "fb"))
    {
        if (argc < MIN_ARGS + 1 || argv[FILE_NAME + 1] == NULL)
        {
            puts("Invalid args!");
            return ARGS_ERR;
        }

        if ((f = fopen(argv[FILE_NAME], "rb")) == NULL)
        {
            puts("Cant open file");
            return file_err;
        }

        if (check_size(f))
        {
            fclose(f);
            return empty_file;
        }

        const int code_err = info_items(f, argv[FILE_NAME + 1]);
        if (code_err != ok)
        {
            fclose(f);
            return code_err;
        }
        fclose(f);

        return ok;
    }

    if (!strcmp(argv[KEY_ARGS], "ab"))
    {
        if ((f = fopen(argv[FILE_NAME], "r+b")) == NULL)
        {
            puts("Cant open file");
            return file_err;
        }
        
        if (check_size(f))
        {
            fclose(f);
            return empty_file;
        }

        const int code_err = enter_structure(f);
        if (code_err != ok)
        {
            fclose(f);
            return code_err;
        }
        puts("Info was added");
        fclose(f);

        return ok;
    }

    return ARGS_ERR;    
}