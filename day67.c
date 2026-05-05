#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void dfs(int v,struct node* adj[],int visited[],int stack[],int *top)
{
    visited[v]=1;
    struct node* temp=adj[v];
    while(temp!=NULL)
    {
        if(!visited[temp->data])
        {
            dfs(temp->data,adj,visited,stack,top);
        }
        temp=temp->next;
    }
    stack[(*top)++]=v;
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

    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    int stack[n],top=0;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,stack,&top);
        }
    }

    for(int i=top-1;i>=0;i--)
    {
        printf("%d",stack[i]);
        if(i>0)
        {
            printf(" ");
        }
    }

    return 0;
}
