#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int dfs(int v,int parent,struct node* adj[],int visited[])
{
    visited[v]=1;
    struct node* temp=adj[v];
    while(temp!=NULL)
    {
        if(!visited[temp->data])
        {
            if(dfs(temp->data,v,adj,visited))
            {
                return 1;
            }
        }
        else if(temp->data!=parent)
        {
            return 1;
        }
        temp=temp->next;
    }
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

        struct node* newnode2=(struct node*)malloc(sizeof(struct node));
        newnode2->data=u;
        newnode2->next=adj[v];
        adj[v]=newnode2;
    }

    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,-1,adj,visited))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
