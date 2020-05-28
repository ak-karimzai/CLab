enum type_error
{
    ok,
    arg_err,
    file_err,
    empty_file,
    put_err,
    get_err,
    error
};

void add_to_file(FILE *f, int n);
void display(FILE *f, int n);
int file_size(FILE *f);
int sort_file(FILE *f, int n);