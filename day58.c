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

struct node* build(int pre[],int in[],int start,int end,int* idx)
{
    if(start>end)
    {
        return NULL;
    }
    struct node* root=newnode(pre[*idx]);
    (*idx)++;
    if(start==end)
    {
        return root;
    }
    int pos=find(in,start,end,root->data);
    root->left=build(pre,in,start,pos-1,idx);
    root->right=build(pre,in,pos+1,end,idx);
    return root;
}

void postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    if(root->right!=NULL||root->left!=NULL)
    {
        printf(" ");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int pre[n],in[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pre[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }
    int idx=0;
    struct node* root=build(pre,in,0,n-1,&idx);
    int stack[1000],top=-1;
    struct node* temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            if(temp->right!=NULL)
            {
                stack[++top]=(long long)temp->right;
            }
            stack[++top]=(long long)temp;
            temp=temp->left;
        }
        if(top==-1)
        {
            break;
        }
        temp=(struct node*)stack[top--];
        if(top!=-1&&temp->right!=NULL&&(struct node*)stack[top]==temp->right)
        {
            stack[top--]= (long long)temp;
            temp=temp->right;
        }
        else
        {
            printf("%d",temp->data);
            if(top!=-1)
            {
                printf(" ");
            }
            temp=NULL;
        }
    }
    return 0;
}
