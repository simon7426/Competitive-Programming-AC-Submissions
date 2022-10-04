#include<stdio.h>
main()
{
    int n,i,a,b,cou=1,max=1;
    scanf("%d",&n);
    scanf("%d",&a);
    for(i=1;i<n;i++)
    {
        scanf("%d",&b);
        if(a<b)
        {
            cou++;
            a=b;
        }
        else
            {
                if(cou>max)
                    max=cou;
                cou=1;
                a=b;
            }
    }
    if(cou>max)
        max=cou;
    printf("%d\n",max);
    return 0;
}