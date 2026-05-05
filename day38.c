#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[2000];
    int front=1000,rear=999;
    for(int i=0;i<n;i++)
    {
        char op[20];
        scanf("%s",op);
        if(strcmp(op,"push_front")==0)
        {
            int x;
            scanf("%d",&x);
            front--;
            a[front]=x;
        }
        else if(strcmp(op,"push_back")==0)
        {
            int x;
            scanf("%d",&x);
            rear++;
            a[rear]=x;
        }
        else if(strcmp(op,"pop_front")==0)
        {
            if(front<=rear)
            {
                front++;
            }
        }
        else if(strcmp(op,"pop_back")==0)
        {
            if(front<=rear)
            {
                rear--;
            }
        }
        else if(strcmp(op,"front")==0)
        {
            if(front<=rear)
            {
                printf("%d\n",a[front]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if(strcmp(op,"back")==0)
        {
            if(front<=rear)
            {
                printf("%d\n",a[rear]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if(strcmp(op,"empty")==0)
        {
            if(front>rear)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(strcmp(op,"size")==0)
        {
            if(front>rear)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n",rear-front+1);
            }
        }
    }
    if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d",a[i]);
            if(i<rear)
            {
                printf(" ");
            }
        }
    }
    return 0;
}
