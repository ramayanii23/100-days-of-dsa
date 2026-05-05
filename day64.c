#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

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

    int s;
    scanf("%d",&s);

    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    int q[n];
    int front=0,rear=0;

    visited[s]=1;
    q[rear++]=s;

    while(front<rear)
    {
        int v=q[front++];
        printf("%d ",v);

        struct node* temp=adj[v];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {
                visited[temp->data]=1;
                q[rear++]=temp->data;
            }
            temp=temp->next;
        }
    }

    return 0;
}
