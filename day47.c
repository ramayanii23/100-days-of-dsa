#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int val)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==0||a[0]==-1)
    {
        return 0;
    }
    struct node* nodes[n];
    for(int i=0;i<n;i++)
    {
        if(a[i]==-1)
        {
            nodes[i]=NULL;
        }
        else
        {
            nodes[i]=newnode(a[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(nodes[i]!=NULL)
        {
            int l=2*i+1;
            int r=2*i+2;
            if(l<n)
            {
                nodes[i]->left=nodes[l];
            }
            if(r<n)
            {
                nodes[i]->right=nodes[r];
            }
        }
    }
    struct node* q[n];
    int front=0,rear=0;
    q[rear++]=nodes[0];
    while(front<rear)
    {
        struct node* temp=q[front++];
        printf("%d",temp->data);
        if(front<rear||temp->left!=NULL||temp->right!=NULL)
        {
            printf(" ");
        }
        if(temp->left!=NULL)
        {
            q[rear++]=temp->left;
        }
        if(temp->right!=NULL)
        {
            q[rear++]=temp->right;
        }
    }
    return 0;
}
