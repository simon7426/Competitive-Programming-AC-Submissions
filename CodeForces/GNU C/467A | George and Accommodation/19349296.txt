#include<stdio.h>
main()
{
    int i=0,n,ro[1000][2],c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&ro[i][1],&ro[i][2]);
    for(i=0;i<n;i++)
    {
        if (ro[i][1]!=ro[i][2]&&(ro[i][1]+1)!=ro[i][2])
            c++;
    }
    printf("%d",c);
    return 0;
}