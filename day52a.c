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

struct node* lca(struct node* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a||root->data==b)
    {
        return root;
    }
    struct node* left=lca(root->left,a,b);
    struct node* right=lca(root->right,a,b);
    if(left!=NULL&&right!=NULL)
    {
        return root;
    }
    if(left!=NULL)
    {
        return left;
    }
    return right;
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
    int x,y;
    scanf("%d %d",&x,&y);
    struct node* ans=lca(nodes[0],x,y);
    if(ans!=NULL)
    {
        printf("%d",ans->data);
    }
    return 0;
}
