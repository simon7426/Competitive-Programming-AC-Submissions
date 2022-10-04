#include<stdio.h>
main()
{
    long long a;
    scanf("%I64d",&a);
    if(a<=2)
        printf("-1\n");
    else if(a%2==1)
        printf("%I64d %I64d\n",(a*a)/2,(a*a)/2+1);
    else
        printf("%I64d %I64d\n",(a*a)/4-1,(a*a)/4+1);
    return 0;
}