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

int find(int in[],int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==val)
        {
            return i;
        }
    }
    return -1;
}

struct node* build(int in[],int post[],int start,int end,int* idx)
{
    if(start>end)
    {
        return NULL;
    }
    struct node* root=newnode(post[*idx]);
    (*idx)--;
    if(start==end)
    {
        return root;
    }
    int pos=find(in,start,end,root->data);
    root->right=build(in,post,pos+1,end,idx);
    root->left=build(in,post,start,pos-1,idx);
    return root;
}

void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d",root->data);
    if(root->left!=NULL||root->right!=NULL)
    {
        printf(" ");
    }
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);
    int in[n],post[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post[i]);
    }
    int idx=n-1;
    struct node* root=build(in,post,0,n-1,&idx);
    preorder(root);
    return 0;
}
