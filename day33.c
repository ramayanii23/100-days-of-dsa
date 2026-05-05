#include <stdio.h>
#include <ctype.h>

int prec(char c)
{
    if(c=='+'||c=='-')
    {
        return 1;
    }
    if(c=='*'||c=='/')
    {
        return 2;
    }
    if(c=='^')
    {
        return 3;
    }
    return 0;
}

int main()
{
    char s[1000],stack[1000];
    int top=-1;
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        char c=s[i];
        if(isalnum(c))
        {
            printf("%c",c);
        }
        else if(c=='(')
        {
            stack[++top]=c;
        }
        else if(c==')')
        {
            while(top!=-1&&stack[top]!='(')
            {
                printf("%c",stack[top--]);
            }
            if(top!=-1)
            {
                top--;
            }
        }
        else
        {
            while(top!=-1&&prec(stack[top])>=prec(c))
            {
                printf("%c",stack[top--]);
            }
            stack[++top]=c;
        }
    }
    while(top!=-1)
    {
        printf("%c",stack[top--]);
    }
    return 0;
}
