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

int length(struct node* head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}

int main()
{
    int n,x,k;
    scanf("%d",&n);
    struct node* head=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        head=insert(head,x);
    }
    scanf("%d",&k);
    if(head==NULL||head->next==NULL)
    {
        struct node* t=head;
        while(t!=NULL)
        {
            printf("%d",t->data);
            if(t->next!=NULL)
            {
                printf(" ");
            }
            t=t->next;
        }
        return 0;
    }
    int len=length(head);
    k=k%len;
    if(k==0)
    {
        struct node* t=head;
        while(t!=NULL)
        {
            printf("%d",t->data);
            if(t->next!=NULL)
            {
                printf(" ");
            }
            t=t->next;
        }
        return 0;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    int steps=len-k;
    struct node* cur=head;
    for(int i=1;i<steps;i++)
    {
        cur=cur->next;
    }
    head=cur->next;
    cur->next=NULL;
    temp=head;
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
