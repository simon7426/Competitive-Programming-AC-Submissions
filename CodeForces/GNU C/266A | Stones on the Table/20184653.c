#include<stdio.h>
main()
{
    char a,b;
    int n,i=0,coun=0;
    scanf("%d ",&n);
    scanf("%c",&a);
    for(i=0;i<n;i++)
    {
        scanf("%c",&b);
        if(b==a)
        {
            coun++;
        }
        else
            a=b;
    }
    printf("%d",coun);
    return 0;
}