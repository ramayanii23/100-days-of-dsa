#include <stdio.h>
#include <limits.h>

struct edge
{
    int u;
    int v;
    int w;
};

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    struct edge e[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    }

    int s;
    scanf("%d",&s);

    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0;

    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[e[j].u]!=INT_MAX&&dist[e[j].u]+e[j].w<dist[e[j].v])
            {
                dist[e[j].v]=dist[e[j].u]+e[j].w;
            }
        }
    }

    for(int j=0;j<m;j++)
    {
        if(dist[e[j].u]!=INT_MAX&&dist[e[j].u]+e[j].w<dist[e[j].v])
        {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(dist[i]==INT_MAX)
        {
            printf("INF");
        }
        else
        {
            printf("%d",dist[i]);
        }
        if(i<n-1)
        {
            printf(" ");
        }
    }

    return 0;
}
