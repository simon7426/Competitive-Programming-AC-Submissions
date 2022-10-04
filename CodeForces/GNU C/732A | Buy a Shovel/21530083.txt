#include<stdio.h>
main()
{
    int i,k,r,m,n;
    scanf("%d %d",&k,&r);
    for(i=1;i<=9;i++)
    {
        n=k*i;
        if((n-r)%10==0||n%10==0)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",10);
    return 0;
 
}