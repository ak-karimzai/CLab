#define ARRAY_SIZE 15
#define PRODUCT_NAME_MAX_SIZE 25

typedef struct 
{
    char product_name[PRODUCT_NAME_MAX_SIZE + 1];
    int price;
} product;

typedef enum 
{
    ok,
    read_err,
    file_err
} error_type;

error_type read_from_file(FILE *is, product *products, const int n);

void print_to_screen(const product *products, const int n, const int user_price);
