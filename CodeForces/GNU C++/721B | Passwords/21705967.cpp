#include<cstdio>
#include<algorithm>
#include<strings.h>
main()
{
    int b[101],n,k,i,j,l,mi,ma,min,max;
    char p[101],tmp[101];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%s",tmp);
        b[i]=strlen(tmp);
    }
    scanf("%s",p);
    l=strlen(p);
    std::sort (b,b+n);
    for(i=0;i<n;i++)
    {
        if(b[i]==l)
        {
            mi=i;
            break;
        }
    }
    ma=n-1;
    for(i=0;i<n;i++)
    {
        if(b[i]>l)
        {
            ma=i-1;
            break;
        }
    }
    min=(mi/k)*(5+k)+(mi%k)+1;
    max=(ma/k)*(5+k)+(ma%k)+1;
    printf("%d %d",min,max);
    return 0;
}