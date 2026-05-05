#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int dfs(int v,struct node* adj[],int visited[],int rec[])
{
    visited[v]=1;
    rec[v]=1;
    struct node* temp=adj[v];
    while(temp!=NULL)
    {
        if(!visited[temp->data])
        {
            if(dfs(temp->data,adj,visited,rec))
            {
                return 1;
            }
        }
        else if(rec[temp->data])
        {
            return 1;
        }
        temp=temp->next;
    }
    rec[v]=0;
    return 0;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    struct node* adj[n];
    for(int i=0;i<n;i++)
    {
        adj[i]=NULL;
    }

    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);

        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=v;
        newnode->next=adj[u];
        adj[u]=newnode;
    }

    int visited[n],rec[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        rec[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,adj,visited,rec))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
