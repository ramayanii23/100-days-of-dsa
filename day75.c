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

    int prefix[n];
    prefix[0]=a[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+a[i];
    }

    int maxlen=0;

    for(int i=0;i<n;i++)
    {
        if(prefix[i]==0)
        {
            if(i+1>maxlen)
            {
                maxlen=i+1;
            }
        }
        for(int j=i+1;j<n;j++)
        {
            if(prefix[j]-prefix[i]==0)
            {
                if(j-i>maxlen)
                {
                    maxlen=j-i;
                }
            }
        }
    }

    printf("%d",maxlen);
    return 0;
}
