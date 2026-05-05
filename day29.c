#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int stack[1000];
    int top=-1;
    for(int i=0;i<n;i++)
    {
        int op,x;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&x);
            top++;
            stack[top]=x;
        }
        else if(op==2)
        {
            if(top==-1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("%d\n",stack[top]);
                top--;
            }
        }
        else if(op==3)
        {
            if(top==-1)
            {
                printf("\n");
            }
            else
            {
                for(int j=top;j>=0;j--)
                {
                    printf("%d",stack[j]);
                    if(j>0)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
