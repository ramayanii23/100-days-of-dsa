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

    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        struct node* temp=adj[i];
        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp=temp->next;
        }
        if(i<n-1)
        {
            printf("\n");
        }
    }

    return 0;
}
