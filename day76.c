#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void dfs(int v,struct node* adj[],int visited[])
{
    visited[v]=1;
    struct node* temp=adj[v];
    while(temp!=NULL)
    {
        if(!visited[temp->data])
        {
            dfs(temp->data,adj,visited);
        }
        temp=temp->next;
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    struct node* adj[n+1];
    for(int i=1;i<=n;i++)
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

        struct node* newnode2=(struct node*)malloc(sizeof(struct node));
        newnode2->data=u;
        newnode2->next=adj[v];
        adj[v]=newnode2;
    }

    int visited[n+1];
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }

    int count=0;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited);
            count++;
        }
    }

    printf("%d",count);
    return 0;
}
