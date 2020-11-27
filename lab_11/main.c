#include <stdio.h>

int decimal_to_octal(int decimal)
{
    int res = 0, mul = 1, last;
    double baqi;
    while (decimal)
    {
        baqi = (double) decimal / 8;
        decimal = (int) baqi;
        baqi -= decimal;
        last = (int) 8 * baqi;
        res += (last * mul);
        mul *= 10;
    }
    return res;
}

int main()
{
    printf("%c", 9 + '0');
}