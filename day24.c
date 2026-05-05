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

struct node* deleteKey(struct node* head,int key)
{
    if(head==NULL)
    {
        return head;
    }
    if(head->data==key)
    {
        struct node* t=head;
        head=head->next;
        free(t);
        return head;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->data==key)
        {
            struct node* t=temp->next;
            temp->next=t->next;
            free(t);
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
    int n,x,key;
    scanf("%d",&n);
    struct node* head=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        head=insert(head,x);
    }
    scanf("%d",&key);
    head=deleteKey(head,key);
    struct node* temp=head;
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
