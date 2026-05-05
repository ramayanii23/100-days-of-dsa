#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node* head,int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
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

struct node* merge(struct node* a,struct node* b)
{
    struct node* head=NULL,*temp=NULL;
    while(a!=NULL&&b!=NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        if(a->data<b->data)
        {
            newnode->data=a->data;
            a=a->next;
        }
        else
        {
            newnode->data=b->data;
            b=b->next;
        }
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    while(a!=NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=a->data;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        a=a->next;
    }
    while(b!=NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=b->data;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        b=b->next;
    }
    return head;
}

int main()
{
    int n,m,x;
    scanf("%d",&n);
    struct node* head1=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        head1=insert(head1,x);
    }
    scanf("%d",&m);
    struct node* head2=NULL;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        head2=insert(head2,x);
    }
    struct node* res=merge(head1,head2);
    struct node* temp=res;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        if(temp->next!=NULL)
        {
            printf(" ");
        }
        temp=temp->next;
    }
    return 0;
}
