#include<stdio.h>
#include<string.h>
main()
{
    char a[1000];
    int i=0;
    gets (a);
    if (a[i]>='a'&&a[i]<='z')
        a[i]-=32;
    puts(a);
    return 0;
}