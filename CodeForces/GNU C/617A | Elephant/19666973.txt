#include<stdio.h>
main()
{
    int a,s;
    scanf("%d",&a);
    s=a/5;
        if(a%5!=0)
            s=s+1;
        printf("%d\n",s);
        return 0;
 
}