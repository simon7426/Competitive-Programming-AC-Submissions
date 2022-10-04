#include<stdio.h>
#include<string.h>
main()
{
    int si,le;
    scanf("%d",&si);
    char wo[1000];
    while(si--)
    {
        scanf("%s",wo);
        le=strlen(wo);
        if (le>10)
            printf("%c%d%c\n",wo[0],le-2,wo[le-1]);
        else
            printf("%s\n",wo);
    }
    return 0;
}