#include<stdio.h>
main()
{
    int a,i,j,ic,jc,k;
    ic=jc=0;
    scanf("%d",&a);
    for(k=0;k<a;k++)
    {
        scanf("%d %d",&i,&j);
        if (i>j)
            ic=ic+1;
        else if (i<j)
            jc=jc+1;
    }
    if(ic>jc)
        printf("Mishka\n");
    else if (jc>ic)
        printf("Chris\n");
    else
        printf("Friendship is magic!^^\n");
    return 0;
}