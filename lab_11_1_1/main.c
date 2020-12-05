#include "./inc/main.h"
#include <assert.h>

bool check_fun(const char *fmt, long num)
{
    bool result = true;
    int size = snprintf(NULL, 0, fmt, num) + 2;
    char *buffer = calloc(size, sizeof(char));
    char *my_buf = calloc(size, sizeof(char));

    for (int i = 0; i < size; i++)
    {
        int write = snprintf(buffer, i, fmt, num);
        int my_write = my_snprintf(my_buf, i, fmt, num);
        if (write != my_write || strcmp(buffer, my_buf) != 0)
        {
            puts("Fayaz");
            printf("%d    dsfdfsdf  %d \n", write != my_write,  strcmp(buffer, my_buf) != 0);
            printf("   snprintf(bif, %d, \"%s\", %ld) = %d, buf = \"%s\"\n", i, fmt, num, write, buffer);
            printf("my_snprintf(bif, %d, \"%s\", %ld) = %d, buf = \"%s\"\n", i, fmt, num, my_write, my_buf);
            result = false;
        }
    }
    if (result == true)
        printf("passed for all %d \n", size);
    
    free(buffer);
    free(my_buf);
    return result;
}

bool check_fun_char(const char *fmt, char num)
{
    bool result = true;
    int size = snprintf(NULL, 0, fmt, num) + 2;
    char *buffer = calloc(size, sizeof(char));
    char *my_buf = calloc(size, sizeof(char));

    for (int i = 0; i < size; i++)
    {
        int write = snprintf(buffer, i, fmt, num);
        int my_write = my_snprintf(my_buf, i, fmt, num);
        if (write != my_write || strcmp(buffer, my_buf) != 0)
        {
            printf("   snprintf(bif, %d, \"%s\", %c) = %d, buf = \"%s\"\n", i, fmt, num, write, buffer);
            printf("my_snprintf(bif, %d, \"%s\", %c) = %d, buf = \"%s\"\n", i, fmt, num, my_write, my_buf);
            result = false;
        }
    }
    if (result == true)
        printf("passed for all %d \n", size);
    
    free(buffer);
    free(my_buf);
    return result;
}

bool check_fun_str(const char *fmt, char *num)
{
    bool result = true;
    int size = snprintf(NULL, 0, fmt, num) + 2;
    char *buffer = calloc(size, sizeof(char));
    char *my_buf = calloc(size, sizeof(char));

    for (int i = 0; i < size; i++)
    {
        int write = snprintf(buffer, i, fmt, num);
        int my_write = my_snprintf(my_buf, i, fmt, num);
        if (write != my_write || strcmp(buffer, my_buf) != 0)
        {
            printf("   snprintf(bif, %d, \"%s\", %s) = %d, buf = \"%s\"\n", i, fmt, num, write, buffer);
            printf("my_snprintf(bif, %d, \"%s\", %s) = %d, buf = \"%s\"\n", i, fmt, num, my_write, my_buf);
            result = false;
        }
    }
    if (result == true)
        printf("passed for all %d \n", size);
    
    free(buffer);
    free(my_buf);
    return result;
}

int main()
{
    check_fun("%o", -2000000000);
    check_fun("%o", 123456789);
    check_fun("%o", 0);
    check_fun("%o", 2000000000);
    check_fun("%o", -123456789);
    // check_fun("%ld", 9223372036854775807);

    check_fun_char("%c", 'c');
    check_fun_char("%c", 'A');
    check_fun_char("%c", 'f');

    check_fun_str("%s", "Ahmad Khalid Karimzai");
    check_fun_str("%s", "Just for testing");
    check_fun_str("%s", "??????????????");

    char str[20];
    my_snprintf(str, 1, "%d", 1);
    // assert(!strcmp(buff1, buff2));
    return 0;
}