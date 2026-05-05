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
    int m;
    scanf("%d",&m);
    int front=0;
    front=(front+m)%n;
    for(int i=0;i<n;i++)
    {
        int idx=(front+i)%n;
        printf("%d",a[idx]);
        if(i<n-1)
        {
            printf(" ");
        }
    }
    return 0;
}
