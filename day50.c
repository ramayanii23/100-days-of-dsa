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

int search(struct node* root,int key)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==key)
    {
        return 1;
    }
    if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

int main()
{
    int n,x,key;
    scanf("%d",&n);
    struct node* root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    scanf("%d",&key);
    if(search(root,key))
    {
        printf("Found");
    }
    else
    {
        printf("Not Found");
    }
    return 0;
}
