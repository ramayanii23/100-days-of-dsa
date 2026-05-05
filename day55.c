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
    int leftToRight=1;

    while(front<rear)
    {
        int size=rear-front;
        int temp[size];

        for(int i=0;i<size;i++)
        {
            struct node* cur=q[front++];
            if(leftToRight)
            {
                temp[i]=cur->data;
            }
            else
            {
                temp[size-1-i]=cur->data;
            }
            if(cur->left!=NULL)
            {
                q[rear++]=cur->left;
            }
            if(cur->right!=NULL)
            {
                q[rear++]=cur->right;
            }
        }

        for(int i=0;i<size;i++)
        {
            printf("%d",temp[i]);
            if(front<rear||i<size-1)
            {
                printf(" ");
            }
        }

        leftToRight=!leftToRight;
    }
    return 0;
}
