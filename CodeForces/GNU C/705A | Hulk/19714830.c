#include<stdio.h>
main()
{
    int i,n;
    scanf("%d",&n);
    for (i=1;i<n;i++)
    {
        if(i&1)
            printf("I hate that ");
        else
            printf("I love that ");
    }
    if (n&1)
        printf("I hate it \n");
    else
        printf("I love it \n");
    return 0;
}