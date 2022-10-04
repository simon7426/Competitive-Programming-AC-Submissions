#include<stdio.h>
main()
{
    long long a;
    scanf("%I64d",&a);
    if(a&1)
        printf("-%I64d\n",(a+1)/2);
    else
        printf("%I64d\n",(a/2));
    return 0;
}