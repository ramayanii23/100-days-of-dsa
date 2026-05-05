#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{
    int n,x;
    scanf("%d",&n);
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&x);
        newnode->data=x;
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
    }
    if(temp!=NULL)
    {
        temp->next=head;
    }
    if(head!=NULL)
    {
        struct node* cur=head;
        do
        {
            printf("%d",cur->data);
            cur=cur->next;
            if(cur!=head)
            {
                printf(" ");
            }
        }
        while(cur!=head);
    }
    return 0;
}
