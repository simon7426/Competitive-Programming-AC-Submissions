#include<stdio.h>
main()
{
    int a[100][100],i,j,nc=1,n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if (a[i][j]=='C'||a[i][j]=='M'||a[i][j]=='Y')
            {
                printf("#Color\n");
                return 0;
            }
        }
    }
    printf("#Black&White\n");
    return 0;
}