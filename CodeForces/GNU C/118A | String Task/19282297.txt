#include<stdio.h>
#include<string.h>
main()
{
    char inp[1000];
    int i,l;
    gets(inp);
    strlwr(inp);
    l=strlen(inp);
    for (i=0;i<l;i++)
    {
        if (inp[i]=='a'||inp[i]=='e'||inp[i]=='i'||inp[i]=='o'||inp[i]=='u'||inp[i]=='y')
        {
            continue;
        }
        printf(".%c",inp[i]);
    }
    return 0;
}