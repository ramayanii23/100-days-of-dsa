#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int v,w;
    struct node* next;
};

struct heapnode
{
    int v,dist;
};

void swap(struct heapnode* a,struct heapnode* b)
{
    struct heapnode t=*a;
    *a=*b;
    *b=t;
}

void heapify(struct heapnode h[],int n,int i)
{
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n&&h[l].dist<h[smallest].dist)
    {
        smallest=l;
    }
    if(r<n&&h[r].dist<h[smallest].dist)
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        swap(&h[i],&h[smallest]);
        heapify(h,n,smallest);
    }
}

void push(struct heapnode h[],int *n,int v,int d)
{
    int i=(*n)++;
    h[i].v=v;
    h[i].dist=d;

    while(i>0&&h[(i-1)/2].dist>h[i].dist)
    {
        swap(&h[i],&h[(i-1)/2]);
        i=(i-1)/2;
    }
}

struct heapnode pop(struct heapnode h[],int *n)
{
    struct heapnode root=h[0];
    h[0]=h[--(*n)];
    heapify(h,*n,0);
    return root;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    struct node* adj[n+1];
    for(int i=1;i<=n;i++)
    {
        adj[i]=NULL;
    }

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);

        struct node* a=(struct node*)malloc(sizeof(struct node));
        a->v=v;a->w=w;a->next=adj[u];
        adj[u]=a;

        struct node* b=(struct node*)malloc(sizeof(struct node));
        b->v=u;b->w=w;b->next=adj[v];
        adj[v]=b;
    }

    int s;
    scanf("%d",&s);

    int dist[n+1];
    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MAX;
    }

    struct heapnode heap[10000];
    int size=0;

    dist[s]=0;
    push(heap,&size,s,0);

    while(size>0)
    {
        struct heapnode cur=pop(heap,&size);
        int u=cur.v;

        if(cur.dist>dist[u])
        {
            continue;
        }

        struct node* temp=adj[u];
        while(temp!=NULL)
        {
            int v=temp->v,w=temp->w;
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                push(heap,&size,v,dist[v]);
            }
            temp=temp->next;
        }
    }

    for(int i=1;i<=n;i++)
    {
        printf("%d",dist[i]);
        if(i<n)
        {
            printf(" ");
        }
    }

    return 0;
}
