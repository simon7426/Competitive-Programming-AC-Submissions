#include<stdio.h>
main()
{
    int t,a,b;
    scanf("%d",&t);
    scanf("%d:%d",&a,&b);
    if(t==12&&a>12)
        a%=10;
    if(b>59)
        b%=10;
    if(t==24&&a>23)
        a%=10;
    if(a==0&&t==12)
        a+=10;
    printf("%02d:%02d",a,b);
    return 0;
}