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

int fill(FILE *f, product arr[MAX_QUANTITY_PROD]);
void sort_struct(product arr[MAX_QUANTITY_PROD], int len);
void write_file(FILE *f, product arr[MAX_QUANTITY_PROD], int len);
int error_substr(char substr[MAX_LEN_STR]);
int display_info(product arr[MAX_QUANTITY_PROD], char *substr, int len);
int fill_new_info(product *new_info);
void write_file(FILE *f, product arr[MAX_QUANTITY_PROD], int len);
void add_struct(product arr[MAX_QUANTITY_PROD], int len);