#include<stdio.h>
main()
{
    int n,w,k,i,sum=0,need;
    scanf("%d %d %d",&k,&n,&w);
    for (i=1;i<=w;i++)
    {
        sum=sum+i*k;
    }
    if(sum>n)
    {
        printf("%d",sum-n);
    }
    else
        printf("0");
    return 0;
}