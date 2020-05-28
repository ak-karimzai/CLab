#include <stdio.h>
#include "my_functions.h"

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