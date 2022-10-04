#include<cstdio>
#include<algorithm>
using namespace std;
main()
{
    int a[101];
    int n,i,m,c=0;
    int sum1=0,sum2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    read:
    for(i=0;i<c;i++)
    {
        sum1+=a[i];
    }
    for(i=c;i<n;i++)
        sum2+=a[i];
    if(sum1>sum2)
    {
        printf("%d\n",c);
        return 0;
    }
    else
    {
        sum1=0;
        sum2=0;
        c++;
        goto read;
    }
}