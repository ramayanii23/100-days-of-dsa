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
    int l1=length(head1),l2=length(head2);
    struct node *p1=head1,*p2=head2;
    int d;
    if(l1>l2)
    {
        d=l1-l2;
        while(d--)
        {
            p1=p1->next;
        }
    }
    else
    {
        d=l2-l1;
        while(d--)
        {
            p2=p2->next;
        }
    }
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data==p2->data)
        {
            printf("%d",p1->data);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }
    printf("No Intersection");
    return 0;
}
