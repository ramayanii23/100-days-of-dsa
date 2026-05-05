#include <stdio.h>
#include <stdlib.h>

struct car
{
    int pos;
    double time;
};

int cmp(const void *a,const void *b)
{
    return ((struct car*)b)->pos-((struct car*)a)->pos;
}

int main()
{
    int n,target;
    scanf("%d %d",&n,&target);

    int position[n],speed[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&position[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&speed[i]);
    }

    struct car a[n];

    for(int i=0;i<n;i++)
    {
        a[i].pos=position[i];
        a[i].time=(double)(target-position[i])/speed[i];
    }

    qsort(a,n,sizeof(struct car),cmp);

    int fleets=0;
    double lastTime=0;

    for(int i=0;i<n;i++)
    {
        if(a[i].time>lastTime)
        {
            fleets++;
            lastTime=a[i].time;
        }
    }

    printf("%d",fleets);
    return 0;
}
