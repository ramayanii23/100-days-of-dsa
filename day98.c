#include <stdio.h>
#include <stdlib.h>

struct interval
{
    int start,end;
};

int cmp(const void *a,const void *b)
{
    return ((struct interval*)a)->start-((struct interval*)b)->start;
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

    qsort(a,n,sizeof(struct interval),cmp);

    int s=a[0].start,e=a[0].end;

    for(int i=1;i<n;i++)
    {
        if(a[i].start<=e)
        {
            if(a[i].end>e)
            {
                e=a[i].end;
            }
        }
        else
        {
            printf("%d %d\n",s,e);
            s=a[i].start;
            e=a[i].end;
        }
    }

    printf("%d %d",s,e);

    return 0;
}
