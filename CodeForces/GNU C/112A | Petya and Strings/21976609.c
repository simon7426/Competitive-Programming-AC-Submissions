#include<stdio.h>
#include<string.h>
main()
{
    char a[101],b[101];
    gets(a);
    gets(b);
    strlwr(a);
    strlwr(b);
    printf("%d\n",strcmp(a,b));
    return 0;
}