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

int isMirror(struct node* a,struct node* b)
{
    if(a==NULL&&b==NULL)
    {
        return 1;
    }
    if(a==NULL||b==NULL)
    {
        return 0;
    }
    if(a->data!=b->data)
    {
        return 0;
    }
    return isMirror(a->left,b->right)&&isMirror(a->right,b->left);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(n==0||arr[0]==-1)
    {
        printf("YES");
        return 0;
    }
    struct node* nodes[n];
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1)
        {
            nodes[i]=NULL;
        }
        else
        {
            nodes[i]=newnode(arr[i]);
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
    if(isMirror(nodes[0],nodes[0]))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
