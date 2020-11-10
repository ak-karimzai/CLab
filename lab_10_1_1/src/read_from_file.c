#include "../inc/read_from_file.h"

void free_prod(product *prod)
{
    if (prod)
    {
        if (prod->product_name)
            free(prod->product_name);
        free(prod);
    }
}

int product_init(product *pro, const char *name, int price)
{
    char *tmp = strdup(name);

    if (tmp)
    {
        free(pro->product_name);

        pro->product_name = tmp;
        pro->price = price;

        return ok;
    }
    return error;
}

product *read_product(FILE *f)
{
    product *prod = malloc(sizeof(product));
    char *buf = NULL;
    size_t len = 0;
    ssize_t read;
    int price;
    int rc = error;
    
    if (prod)
    {
        if ((read = getline(&buf, &len, f)) > 0)
        {
            if (fscanf(f, "%d\n", &price) == 1)
            {
                if (price > 0)
                    rc = product_init(prod, buf, price);
                else
                    rc = error;
            }
        }
        free(buf);
    }
    else
        rc = error;
    if (rc == error)
    {
        free_prod(prod);
        prod = NULL;
    }
    return prod;
}

node_t *create_node(FILE *input_file)
{
    product *pro = read_product(input_file);
    node_t *temp = NULL;
    if (pro)
    {
        temp = malloc(sizeof(node_t));
        if (temp)
        {
            temp->data = pro;
            temp->next = NULL;
        }
        else
            free_prod(pro);
    }
    return temp;
}