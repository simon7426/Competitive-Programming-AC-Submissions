#include<cstdio>
#include<strings.h>
main()
{
    char a[100001];
    gets(a);
    int u=0,d=0,l=0,r=0,ud,lr;
    int le,i;
    le= strlen(a);
    if (le%2!=0)
    {
        printf("-1\n");
        return 0;
    }
    for(i=0;i<le;i++)
    {
        switch (a[i])
        {
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            case 'R':
                r++;
                break;
            case 'L':
                l++;
                break;
            default:
                break;
        }
   }
   u>=d?ud=u-d:ud=d-u;
   l>=r?lr=l-r:lr=r-l;
   printf("%d\n",(ud+lr)/2);
   return 0;
}