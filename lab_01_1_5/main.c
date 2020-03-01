#include<stdio.h>

int Pow(int m, int n)
{
   int i, s = 1;
   if (n == 0)
   {
      return 1;
   }
   for (i = 0; i < n; i++)
   {
      s *= m;
   }
   return s;
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
   if (r == 2)
   {
   printf("%d", Pow(a, n));
   return 0;
   }
   else
   {
   printf("input error");
   return 1;
   }
}