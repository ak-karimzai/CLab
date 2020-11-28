#include <stdio.h>
#include <inttypes.h>
int main()
{
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(int));
    return sizeof(long int) == sizeof(int32_t);
}