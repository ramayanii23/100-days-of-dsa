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
    for(int i=0;i<=n/2-1;i++)
    {
        int l=2*i+1;
        int r=2*i+2;
        if(l<n&&a[i]>a[l])
        {
            printf("NO");
            return 0;
        }
        if(r<n&&a[i]>a[r])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
