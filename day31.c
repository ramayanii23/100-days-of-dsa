#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node* next;
};

struct node* insert(struct node* head,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->exp=e;
    newnode->next=NULL;
    if(head==NULL)
    {
        return newnode;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

int main()
{
    int n,c,e;
    scanf("%d",&n);
    struct node* head=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&c,&e);
        head=insert(head,c,e);
    }
    struct node* temp=head;
    while(temp!=NULL)
    {
        if(temp->exp==0)
        {
            printf("%d",temp->coef);
        }
        else if(temp->exp==1)
        {
            printf("%dx",temp->coef);
        }
        else
        {
            printf("%dx^%d",temp->coef,temp->exp);
        }
        if(temp->next!=NULL)
        {
            printf(" + ");
        }
        temp=temp->next;
    }
    return 0;
}
