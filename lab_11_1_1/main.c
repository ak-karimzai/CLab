#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

int my_snprintf(char *str_s, size_t n, const char *str_format, ...);
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

int main()
{
    check_fun("%d", 12321);
    check_fun("%d", 12321);
    printf("%d\n", sizeof(long) == sizeof(int64_t));
    // char arr[20];
    printf("%d\n", sizeof(int) == sizeof(int32_t));
    return 0;
}