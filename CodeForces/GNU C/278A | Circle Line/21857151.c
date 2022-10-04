#include<stdio.h>
main()
{
    int n,a[101],s,e,i,s1=0,s2=0,t1,t2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d %d",&t1,&t2);
    if(t1==t2)
    {
        printf("0\n");
        return 0;
    }
    else if(t1>t2)
    {
        s=t2-1;
        e=t1-2;
    }
    else
    {
        s=t1-1;
        e=t2-2;
    }
    for(i=s;i<=e;i++)
    {
        s1+=a[i];
    }
    for(i=0;i<n;i++)
    {
        if(i>=s&&i<=e)
            continue;
        else
            s2+=a[i];
    }
    s1>s2?printf("%d\n",s2):printf("%d\n",s1);
    return 0;
}