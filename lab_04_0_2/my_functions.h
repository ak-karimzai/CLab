enum error_type
{
    ok,
    input_err,
    size_err,
    no_words,
    empty_string,
    err_word_size
};

#define N 256

void lexem_repeat_search_search(char matr_1[][N], int *len_matr1);

int split(const char *const str, char matrix_split[][N], int *const count_lexem);

int read_string(char *const arr);