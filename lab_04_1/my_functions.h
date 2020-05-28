#define STR_SIZE 240
#define TEST_NUM 5

enum error_type
{
    ok,
    error
};

int check_usr_strpbrk(const char *str1, const char *str2);

int test_usr_strspn(const char *str1, const char *str2);

int test_usr_strcspn(const char *str1, const char *str2);

int test_usr_strchr(const char *str1, int str2);

int test_usr_strrchr(const char *str1, int str2);

void print_result(const int test_numb, const int test_res);
