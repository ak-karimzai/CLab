#include<stdio.h>
#include<math.h>

int main()
{
   int a, b;
   printf("number of coins\n");
   scanf("%d", &a);
   b = (a - 20) / 25;
   printf("number of bootles\n");
   printf("%d", b);
   return 0;
}