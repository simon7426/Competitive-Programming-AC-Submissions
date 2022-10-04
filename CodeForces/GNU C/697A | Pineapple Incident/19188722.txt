#include<stdio.h>
main()
{
    int t,s,x;
    scanf("%d %d %d",&t,&s,&x);
    if (x==t)
    {
        printf("YES");
        goto re;
    }
    else
        t=s+t;
 
    read:
        if (x<t+s)
        {
            if (x==t+s||x==t+s+1||x==t||x==t+1)
                printf("YES");
            else
                printf("NO");
        }
        else
        {
            t=t+s;
            goto read;
        }
    re:
        return 0;
}