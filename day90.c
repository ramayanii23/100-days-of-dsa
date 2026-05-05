#include <stdio.h>

int canPaint(int a[],int n,int k,int maxTime)
{
    int painters=1,sum=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>maxTime)
        {
            return 0;
        }
        if(sum+a[i]<=maxTime)
        {
            sum+=a[i];
        }
        else
        {
            painters++;
            sum=a[i];
            if(painters>k)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int a[n];
    int max=0,sum=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
        {
            max=a[i];
        }
        sum+=a[i];
    }

    int l=max,r=sum,ans=sum;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(canPaint(a,n,k,mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    printf("%d",ans);
    return 0;
}
