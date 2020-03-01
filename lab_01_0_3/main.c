#include<stdio.h>
#include<math.h>

int main()
{
   //h height in cm t, t circle diameter m wight in kg find weight in 
   //
   float h, t, m, weight, mass;
   scanf("%f%f%f", &h, &t, &m);
   weight = h * t / 240;
   printf("normal weight:");
   printf("%f\n", weight);
   h = h / 100;
   mass = m / (h * h);
   printf("mass: ");
   printf("%f\n", mass);
   return 0;
}