#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);

    char names[n][100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",names[i]);
    }

    int count[n];
    for(int i=0;i<n;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(count[i]!=-1)
        {
            count[i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(strcmp(names[i],names[j])==0)
                {
                    count[i]++;
                    count[j]=-1;
                }
            }
        }
    }

    int max=0;
    char res[100];

    for(int i=0;i<n;i++)
    {
        if(count[i]!=-1)
        {
            if(count[i]>max)
            {
                max=count[i];
                strcpy(res,names[i]);
            }
            else if(count[i]==max)
            {
                if(strcmp(names[i],res)<0)
                {
                    strcpy(res,names[i]);
                }
            }
        }
    }

    printf("%s %d",res,max);
    return 0;
}
