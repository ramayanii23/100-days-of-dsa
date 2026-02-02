#include <stdio.h>

int main() 
{
    int n, pos;
    int arr[100];

    // Read size
    scanf("%d", &n);

    // enter elements in array
    for (int i = 0; i < n; i++)
     {
        scanf("%d", &arr[i]);
    }

    // Read position where to delete from
    scanf("%d", &pos);

    
    for (int i = pos - 1; i < n - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }


    for (int i = 0; i < n - 1; i++)
     {
        printf("%d ", arr[i]);
    }

    return 0;
}
