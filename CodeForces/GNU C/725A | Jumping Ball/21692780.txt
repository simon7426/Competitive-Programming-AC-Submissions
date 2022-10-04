#include<stdio.h>
main()
{
    int n,i,c=0;
    scanf("%d",&n);
    char a[n];
    scanf("%s",a);
    for (i=0;a[i]=='<';i++)
    {
        c++;
    }
    for(i=n-1;a[i]=='>';i--)
        c++;
    printf("%d",c);
    return 0;
 
}