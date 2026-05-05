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
    int count=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            count++;
        }
        temp=temp->next;
    }
    printf("%d",count);
    return 0;
}
