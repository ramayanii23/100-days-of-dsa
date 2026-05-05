#include <stdio.h>
#include <stdlib.h>

struct interval
{
    int start,end;
};

int cmpStart(const void *a,const void *b)
{
    return ((struct interval*)a)->start-((struct interval*)b)->start;
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int h[],int n,int i)
{
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n&&h[l]<h[smallest])
    {
        smallest=l;
    }
    if(r<n&&h[r]<h[smallest])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        swap(&h[i],&h[smallest]);
        heapify(h,n,smallest);
    }
}

void push(int h[],int *n,int val)
{
    int i=(*n)++;
    h[i]=val;

    while(i>0&&h[(i-1)/2]>h[i])
    {
        swap(&h[i],&h[(i-1)/2]);
        i=(i-1)/2;
    }
}

int pop(int h[],int *n)
{
    int root=h[0];
    h[0]=h[--(*n)];
    heapify(h,*n,0);
    return root;
}

int main()
{
    int n;
    scanf("%d",&n);

    struct interval a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].start,&a[i].end);
    }

    qsort(a,n,sizeof(struct interval),cmpStart);

    int heap[n],size=0;

    push(heap,&size,a[0].end);

    for(int i=1;i<n;i++)
    {
        if(a[i].start>=heap[0])
        {
            pop(heap,&size);
        }
        push(heap,&size,a[i].end);
    }

    printf("%d",size);
    return 0;
}
