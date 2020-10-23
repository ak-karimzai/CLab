#include <stdio.h>
#include <stdlib.h>

enum error_code
{
    ok,
    error
};

typedef struct
{
    char *product_name;
    int price;
} product;

int num_of_objs(FILE *input_file)
{
    char *line = NULL;
    ssize_t read;
    size_t len;
    int x, count = 0;
    while ((read = getline(&line, &len, input_file)) != -1 && \
                       fscanf(input_file, "%d\n", &x) == 1)
    {
        printf("%s\n%d\n", line, x);
        count++;
    }
    
    free(line);
    if (!(feof(input_file) || fgetc(input_file) == EOF))
        return 0;
    return count;
}

int main()
{
    FILE *input_file = fopen("in_1.txt", "r");
    if (input_file)
        num_of_objs(input_file);
    return 0;
}