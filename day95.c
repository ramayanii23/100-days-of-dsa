#include <stdio.h>

void insertionSort(float a[],int n)
{
    for(int i=1;i<n;i++)
    {
        float key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    float a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }

    float bucket[n][n];
    int count[n];

    for(int i=0;i<n;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        int idx=a[i]*n;
        bucket[idx][count[idx]++]=a[i];
    }

    for(int i=0;i<n;i++)
    {
        insertionSort(bucket[i],count[i]);
    }

    int k=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<count[i];j++)
        {
            a[k++]=bucket[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%.6f",a[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }

    return 0;
}
