#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d",&n);

    int dist[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            if(x==-1&&i!=j)
            {
                dist[i][j]=INT_MAX;
            }
            else
            {
                dist[i][j]=x;
            }
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX)
                {
                    if(dist[i][k]+dist[k][j]<dist[i][j])
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INT_MAX)
            {
                printf("-1");
            }
            else
            {
                printf("%d",dist[i][j]);
            }
            if(j<n-1)
            {
                printf(" ");
            }
        }
        if(i<n-1)
        {
            printf("\n");
        }
    }

    return 0;
}
