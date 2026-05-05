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

struct node* insert(struct node* root,int val)
{
    if(root==NULL)
    {
        return newnode(val);
    }
    if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else
    {
        root->right=insert(root->right,val);
    }
    return root;
}

int lca(struct node* root,int a,int b)
{
    if(root==NULL)
    {
        return -1;
    }
    if(a<root->data&&b<root->data)
    {
        return lca(root->left,a,b);
    }
    if(a>root->data&&b>root->data)
    {
        return lca(root->right,a,b);
    }
    return root->data;
}

int main()
{
    int n,x,a,b;
    scanf("%d",&n);
    struct node* root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    scanf("%d %d",&a,&b);
    printf("%d",lca(root,a,b));
    return 0;
}
