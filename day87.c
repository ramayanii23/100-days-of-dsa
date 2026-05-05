#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    int x;
    scanf("%d",&x);

    int l=0,r=n-1,found=0;

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]==x)
        {
            printf("Found");
            found=1;
            break;
        }
        else if(a[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    if(!found)
    {
        printf("Not Found");
    }

    return 0;
}
