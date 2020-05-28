#define N 257

enum error_type
{
    ok,
    input_err
};

int read_string(char *array);
int split(const char *const string, char matrix[][N], int *const count);
void set_string(char matrix[][N], int count);
void set_string_1(char matrix[][N], int *count);