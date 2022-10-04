#include<stdio.h>
main()
{
    char a[1000];
    int n,d,i,j,count=0,max=0;
    scanf("%d %d ",&n,&d);
    for(i=0;i<d;i++)
    {
        gets(a);
        for(j=0;j<=n;j++)
        {
            if(a[j]=='1')
            {
                continue;
            }
            else if (a[j]=='0')
            {
                count++;
                break;
            }
            else if(a[j]=='\0')
                {
                    max=(max<count)?count:max;
                    count=0;
                }
        }
    }
    max>count?printf("%d",max):printf("%d",count);
    return 0;
}