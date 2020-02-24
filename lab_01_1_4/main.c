#include<stdio.h>
#include<math.h>

void find_floor()
{
    int x,E,f;
    scanf("%d",&x);
    E = (x - 1) / 36 + 1;
    f = ((x - (E - 1) * 36) - 1) / 4 + 1;
    printf("%d %d",E,f);
    
}

int main()
{
    find_floor();
}