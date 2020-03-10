#include <stdio.h>
#include <math.h>
#define N 100

int append(int A[], int i, int n)
{
    if (n)
    {
        A[i] = n;
	return 0;
    }
    return -1;
}
int main()
{
    int A[N] = {0}, geo_mean = 1.0, x;
    int i, n;
    printf("Enter the size of array.\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        append(A, i, x);
    }
    for (i = 0; i < n; i++)
    {
        if (A[i] % 2 != 0)
        {
            geo_mean *= A[i];
        }
    }
    printf("geometrical mean is equal: \n");
    printf("%d", geo_mean);
    return 0;
}
