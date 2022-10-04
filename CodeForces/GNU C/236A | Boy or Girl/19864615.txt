#include<stdio.h>
#include<string.h>
main()
{
    char name[1000];
    int i=0,j=0,k=0;
    int size;
    gets(name);
    size=strlen(name);
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if (name[i]==name[j])
            {
                for(k=j;k<size;k++)
                {
                    name[k]=name[k+1];
                }
                j--;
                size--;
            }
        }
    }
    if (size & 1)
        printf("IGNORE HIM!\n");
    else
        printf("CHAT WITH HER!\n");
    return 0;
}