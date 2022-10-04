#include<stdio.h>
main()
{
    int n,k,c=0,i;
    int a[100];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++)
    {
        if (a[k-1]!=0)
        {
        if (a[k-1]<=a[i])
            c++;
        }
        else
        {
            if (a[i]>0)
                c++;
        }
    }
    printf("%d",c);
}