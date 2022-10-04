#include<stdio.h>
main()
{
    int a[1000],n,i,j,k,oc=0,ec=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            ec++;
            j=i+1;
        }
        else
        {
            oc++;
            k=i+1;
        }
    }
    if (oc==1)
        printf("%d",k);
    if(ec==1)
        printf("%d",j);
    return 0;
}