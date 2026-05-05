#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node* next;
};

struct node* push(struct node* top,int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    return newnode;
}

struct node* pop(struct node* top,int* val)
{
    if(top==NULL)
    {
        return NULL;
    }
    struct node* temp=top;
    *val=temp->data;
    top=top->next;
    free(temp);
    return top;
}

int main()
{
    char s[1000];
    struct node* top=NULL;
    fgets(s,sizeof(s),stdin);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')
        {
            continue;
        }
        if(isdigit(s[i]))
        {
            int num=0;
            while(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
                i++;
            }
            i--;
            top=push(top,num);
        }
        else
        {
            int b,a;
            top=pop(top,&b);
            top=pop(top,&a);
            int res;
            if(s[i]=='+')
            {
                res=a+b;
            }
            else if(s[i]=='-')
            {
                res=a-b;
            }
            else if(s[i]=='*')
            {
                res=a*b;
            }
            else if(s[i]=='/')
            {
                res=a/b;
            }
            top=push(top,res);
        }
    }
    int result;
    top=pop(top,&result);
    printf("%d",result);
    return 0;
}
