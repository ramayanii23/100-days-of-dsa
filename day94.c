#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int a[n];
    int max=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    int freq[max+1];
    for(int i=0;i<=max;i++)
    {
        freq[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;
    }

    for(int i=1;i<=max;i++)
    {
        freq[i]+=freq[i-1];
    }

    int output[n];

    for(int i=n-1;i>=0;i--)
    {
        output[freq[a[i]]-1]=a[i];
        freq[a[i]]--;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d",output[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }

    return 0;
}
