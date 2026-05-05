#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val,idx;
};

void merge(struct node a[],int l,int m,int r,int count[])
{
    int n1=m-l+1;
    int n2=r-m;

    struct node L[n1],R[n2];

    for(int i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=a[m+1+j];
    }

    int i=0,j=0,k=l,rightCount=0;

    while(i<n1&&j<n2)
    {
        if(L[i].val<=R[j].val)
        {
            count[L[i].idx]+=rightCount;
            a[k++]=L[i++];
        }
        else
        {
            rightCount++;
            a[k++]=R[j++];
        }
    }

    while(i<n1)
    {
        count[L[i].idx]+=rightCount;
        a[k++]=L[i++];
    }

    while(j<n2)
    {
        a[k++]=R[j++];
    }
}

void mergesort(struct node a[],int l,int r,int count[])
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(a,l,m,count);
        mergesort(a,m+1,r,count);
        merge(a,l,m,r,count);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    struct node a[n];
    int count[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].val);
        a[i].idx=i;
        count[i]=0;
    }

    mergesort(a,0,n-1,count);

    for(int i=0;i<n;i++)
    {
        printf("%d",count[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }

    return 0;
}
