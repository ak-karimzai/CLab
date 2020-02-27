#include<stdio.h>
#include<math.h>

void find_floor()
{
    int x, e, f;
    scanf("%d", &x);
    e = (x - 1) / 36 + 1;
    f = ((x - (e - 1) * 36) - 1) / 4 + 1;
    printf("%d %d", e, f);
    
}

int main()
{
    find_floor();
}
