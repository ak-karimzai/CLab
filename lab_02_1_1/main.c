#include <stdio.h>
#include <math.h>
#define N 100

int append(int a[], int i, int n)
{
    if (n)
    {
        a[i] = n;
	return 0;
    }
    return -1;
}
int main()
{
    int a[N] = {0}, geo_mean = 1.0, x;
    int i, n, rc = 0;
    printf("Enter the size of array.\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        rc = scanf("%d", &x);
        if (rc)
            append(a, i, x);
        else
        {
            printf("inPut Error!\n");
            return -1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            geo_mean *= a[i];
        }
    }
    printf("geometrical mean is equal: \n");
    printf("%d", geo_mean);
    return 0;
}
