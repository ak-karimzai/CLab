#include <stdio.h>
#include <inttypes.h>
int main()
{
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(int));
    return sizeof(int) == sizeof(int32_t);
}