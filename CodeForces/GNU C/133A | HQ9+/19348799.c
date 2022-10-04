#include<stdio.h>
#include<string.h>
main()
{
    char pg[1000];
    gets(pg);
    int l,i=0;
    l=strlen(pg);
    for(i=0;i<=l;i++)
    {
        if(pg[i]==72||pg[i]==81||pg[i]==57)
            {
                printf("YES");
                break;
            }
        else if (i==l)
        {
            printf("NO");
        }
    }
    return 0;
}