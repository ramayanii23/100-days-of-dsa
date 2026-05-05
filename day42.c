#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int q[n],s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    int top=-1;
    for(int i=0;i<n;i++)
    {
        s[++top]=q[i];
    }
    int front=0;
    while(top!=-1)
    {
        q[front++]=s[top--];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",q[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }
    return 0;
}
