#include<stdio.h>
main()
{
    int i,j,k,m,n;
    scanf("%d",&n);
    if (n>=4)
    {
        if (n%3==1)
    {
        i=(n-1)/3;
        j=(n-1)/3;
        k=(n-1)/3;
    }
    else if (n%3==2)
    {
        i=(n-1)/3+1;
        j=(n-1)/3;
        k=(n-1)/3;
    }
    else if (n%3==0)
    {
        i=(n-1)/3+1;
        j=(n-1)/3+1;
        k=(n-1)/3;
    }
    }
    else
    {
       if (n%3==0)
    {
        i=n/3;
        j=n/3;
        k=0;
    }
    else if (n%3==1)
    {
        i=n/3+1;
        j=k=n/3;
    }
    else if (n%3==2)
    {
        i=j=n/3+1;
        k=(n-1)/3;
    }
    }
    printf("+------------------------+\n");
    printf("|");
    for(m=1;m<=i;m++)
        printf("O.");
    for(m=1;m<=11-i;m++)
        printf("#.");
    printf("|D|)\n");
    printf("|");
    for(m=1;m<=j;m++)
        printf("O.");
    for(m=1;m<=11-j;m++)
        printf("#.");
    printf("|.|\n");
    (n>2)?printf("|O.......................|\n"):printf("|#.......................|\n");
    printf("|");
    for(m=1;m<=k;m++)
        printf("O.");
    for(m=1;m<=11-k;m++)
        printf("#.");
    printf("|.|)\n");
    printf("+------------------------+\n");
    return 0;
}