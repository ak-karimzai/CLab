#include<stdio.h>

int pow(int m, int n)
{
   if (n == 0)
      return 1;
   return m * pow(m, n - 1);
}
int main()
{
   int a, n, r;
   r = scanf("%d%d", &a, &n);
   if (n < 0)
   {
      printf("incorect input");
      return 2;
   }
   if(r == 2)
   {
      printf("%d", pow(a, n));
      return 0;
   }
   else
   {
      printf("input error");
      return 1;
   }
}