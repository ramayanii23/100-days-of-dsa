#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int hd;
    struct node* left;
    struct node* right;
};

struct node* newnode(int val)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->hd=0;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==0||a[0]==-1)
    {
        return 0;
    }
    struct node* nodes[n];
    for(int i=0;i<n;i++)
    {
        if(a[i]==-1)
        {
            nodes[i]=NULL;
        }
        else
        {
            nodes[i]=newnode(a[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(nodes[i]!=NULL)
        {
            int l=2*i+1;
            int r=2*i+2;
            if(l<n)
            {
                nodes[i]->left=nodes[l];
            }
            if(r<n)
            {
                nodes[i]->right=nodes[r];
            }
        }
    }

    struct node* q[n];
    int hd[n],level[n];
    int front=0,rear=0;

    q[rear]=nodes[0];
    hd[rear]=0;
    level[rear]=0;
    rear++;

    int min=0,max=0;

    struct
    {
        int hd;
        int lvl;
        int val;
    } arr[1000];

    int k=0;

    while(front<rear)
    {
        struct node* temp=q[front];
        int h=hd[front];
        int l=level[front];
        front++;

        arr[k].hd=h;
        arr[k].lvl=l;
        arr[k].val=temp->data;
        k++;

        if(h<min)
        {
            min=h;
        }
        if(h>max)
        {
            max=h;
        }

        if(temp->left!=NULL)
        {
            q[rear]=temp->left;
            hd[rear]=h-1;
            level[rear]=l+1;
            rear++;
        }
        if(temp->right!=NULL)
        {
            q[rear]=temp->right;
            hd[rear]=h+1;
            level[rear]=l+1;
            rear++;
        }
    }

    for(int i=min;i<=max;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int p=j+1;p<k;p++)
            {
                if(arr[j].hd==arr[p].hd&&arr[j].lvl>arr[p].lvl)
                {
                    int t1=arr[j].lvl;
                    int t2=arr[j].val;
                    arr[j].lvl=arr[p].lvl;
                    arr[j].val=arr[p].val;
                    arr[p].lvl=t1;
                    arr[p].val=t2;
                }
            }
        }
        for(int j=0;j<k;j++)
        {
            if(arr[j].hd==i)
            {
                printf("%d",arr[j].val);
                int flag=0;
                for(int p=j+1;p<k;p++)
                {
                    if(arr[p].hd==i)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                {
                    printf(" ");
                }
            }
        }
        if(i<max)
        {
            printf("\n");
        }
    }
    return 0;
}
