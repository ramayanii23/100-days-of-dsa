#include <stdio.h>

int main() 
{
    int n, k, i, c = 0;
    int a[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    for (i = 0; i < n; i++) 
    {
        c++;
        if (a[i] == k)
         {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", c);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d", c);

    return 0;
}
