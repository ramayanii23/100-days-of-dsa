#include <stdio.h>
#include <string.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int main()
{
    int n;
    scanf("%d",&n);
    int h[1000];
    int size=0;
    for(int i=0;i<n;i++)
    {
        char op[20];
        scanf("%s",op);
        if(strcmp(op,"insert")==0)
        {
            int x;
            scanf("%d",&x);
            int j=size;
            h[size++]=x;
            while(j>0&&h[(j-1)/2]>h[j])
            {
                swap(&h[(j-1)/2],&h[j]);
                j=(j-1)/2;
            }
        }
        else if(strcmp(op,"peek")==0)
        {
            if(size==0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",h[0]);
            }
        }
        else if(strcmp(op,"extractMin")==0)
        {
            if(size==0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",h[0]);
                h[0]=h[size-1];
                size--;
                int j=0;
                while(1)
                {
                    int l=2*j+1,r=2*j+2,small=j;
                    if(l<size&&h[l]<h[small])
                    {
                        small=l;
                    }
                    if(r<size&&h[r]<h[small])
                    {
                        small=r;
                    }
                    if(small!=j)
                    {
                        swap(&h[j],&h[small]);
                        j=small;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
