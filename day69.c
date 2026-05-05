#include <stdio.h>
#include <limits.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;
    }

    int s;
    scanf("%d",&s);

    int dist[n],visited[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=0;
    }

    dist[s]=0;

    for(int i=0;i<n-1;i++)
    {
        int min=INT_MAX,u=-1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&&dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        if(u==-1)
        {
            break;
        }

        visited[u]=1;

        for(int v=0;v<n;v++)
        {
            if(graph[u][v]&&!visited[v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
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
