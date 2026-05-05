#include <stdio.h>

int canAllocate(int a[],int n,int m,int maxPages)
{
    int students=1,sum=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>maxPages)
        {
            return 0;
        }
        if(sum+a[i]<=maxPages)
        {
            sum+=a[i];
        }
        else
        {
            students++;
            sum=a[i];
            if(students>m)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

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

        if(canAllocate(a,n,m,mid))
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
