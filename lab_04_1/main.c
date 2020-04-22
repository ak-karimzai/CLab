#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define STR_SIZE 240
#define TEST_NUM 5

enum error_type
{
    ok,
    error
};

char *usr_strpbrk(const char *str_1, const char *str_2)
{
    if (!str_1 || !str_2)
        return NULL;
    
    int i = 0, j = 0;

    while (str_1[i])
    {
        while (str_2[j])
        {
            if (str_2[j] == str_1[i])
                return (char *)&str_1[i];
            j++;
        }
        j = 0;
        i++;
    }
    return NULL;
}

size_t usr_strspn(const char *str_1, const char *str_2)
{
    if (!str_1 || !str_2)
        return 0;

    size_t i = 0, j = 0;

    while (str_1[i])
    {
        int is_in_str2 = 0;

        while (str_2[j])
        {
            if (str_2[j] == str_1[i])
            {
                is_in_str2 = 1;
                break;
            }
            j++;
        }
        if (is_in_str2 == 0)
            return i;
        else
        {
            j = 0;
            i++;
        }
    }
    return i;
}

size_t usr_strcspn(const char *str_1, const char *str_2)
{
    if (!str_1 || !str_2)
        return ok;

    size_t i = 0, j =0;
    
    while (str_1[i])
    {
        int if_in_str2 = 0;
        
        while (str_2[j])
        {
            if (str_2[j] == str_1[i])
            {
                if_in_str2 = 1;
                break;
            }
            j++;
        }
        if (if_in_str2)
            return i;
        else
        {
            j = 0;
            i++;
        }
    }
    
    return i;
}

char *usr_strchr(const char *str_1, int str_2)
{
    char *res = NULL;

    if (!str_1 || !str_2)
        return NULL;
    
    int i = 0;

    while (str_1[i])
    {
        if (str_1[i] == str_2)
            return (char *)&str_1[i];

        i++;
    }

    if (str_2 == 0)
    {
        res = (char *)&str_1[i];
        return res;
    }

    return NULL;
}

char *usr_strrchr(const char *str_1, int str_2)
{
    char *res = NULL;

    if (!str_1 || str_2 < 0 || str_2 > 255)
        return NULL;
    
    int i = 0;

    while (str_1[i])
    {
        if (str_1[i] == str_2)
            res = (char *)&str_1[i];
        i++;
    }
    
    if (str_2 == 0)
        res = (char *)&str_1[i];
    
    return res;
}

int check_usr_strpbrk(const char *str1, const char *str2)
{
    if (strpbrk(str1, str2) != usr_strpbrk(str1, str2))
        return error;
    return ok;
}

int test_usr_strspn(const char *str1, const char *str2)
{
    if (strspn(str1, str2) != usr_strspn(str1, str2))
        return error;
    return ok;
}

int test_usr_strcspn(const char *str1, const char *str2)
{
    if (strcspn(str1, str2) != usr_strcspn(str1, str2))
        return error;
    return ok;
}

int test_usr_strchr(const char *str1, int str2)
{
    if (strchr(str1, str2) != usr_strchr(str1, str2))
        return error;
    return ok;
}

int test_usr_strrchr(const char *str1, int str2)
{
    if (strrchr(str1, str2) != usr_strrchr(str1, str2))
        return error;
    return ok;
}

void print_result(const int test_numb, const int test_res)
{
    printf("test #%d: Result - %d\n", test_numb, test_res);
}

int main()
{
    const char tests_string[TEST_NUM][STR_SIZE] = {
        "this is a test",
        "your dress is good",
        "time to get it get it tyga",
        "supa hot hella hillz",
        ""
        };

    const char tests_substring[TEST_NUM][STR_SIZE] = {
        " absj",
        "osir",
        "tyga",
        "",
        " asdfre"
        };

    const char tests_char[TEST_NUM] = {
        't',
        'd',
        ' ',
        'h',
        'b',
        };

    printf("0 - Test completed, 1 - Test failed\n");

    printf("\nStrpbrk tests:\n");
    for (int i = 0; i < TEST_NUM; ++i)
        print_result(i + 1, check_usr_strpbrk(tests_string[i], tests_substring[i]));

    printf("\nStrspn tests:\n");
    for (int i = 0; i < TEST_NUM; ++i)
        print_result(i + 1, test_usr_strspn(tests_string[i], tests_substring[i]));

    printf("\nStrcspn tests:\n");
    for (int i = 0; i < TEST_NUM; ++i)
        print_result(i + 1, test_usr_strcspn(tests_string[i], tests_substring[i]));

    printf("\nStrchr tests:\n");
    for (int i = 0; i < TEST_NUM; ++i)
        print_result(i + 1, test_usr_strchr(tests_string[i], tests_char[i]));

    printf("\nStrrchr tests:\n");
    for (int i = 0; i < TEST_NUM; ++i)
        print_result(i + 1, test_usr_strrchr(tests_string[i], tests_char[i]));

    return ok;
}