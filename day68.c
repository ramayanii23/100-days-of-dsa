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

    int indegree[n];
    for(int i=0;i<n;i++)
    {
        indegree[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);

        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=v;
        newnode->next=adj[u];
        adj[u]=newnode;

        indegree[v]++;
    }

    int q[n];
    int front=0,rear=0;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q[rear++]=i;
        }
    }

    int count=0;

    while(front<rear)
    {
        int v=q[front++];
        printf("%d",v);
        count++;
        if(front<rear||count<n)
        {
            printf(" ");
        }

        struct node* temp=adj[v];
        while(temp!=NULL)
        {
            indegree[temp->data]--;
            if(indegree[temp->data]==0)
            {
                q[rear++]=temp->data;
            }
            temp=temp->next;
        }
    }

    return 0;
}
