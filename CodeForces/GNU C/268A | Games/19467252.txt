#include<stdio.h>
main()
{
    int a[1000][2];
    int n,i,j,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
    {
        if (a[i][0]==a[j][1])
            count++;
    }
    printf("%d",count);
}