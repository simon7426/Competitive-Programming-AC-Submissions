#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int d[100100],h[100100];
main()
{
    int n,m,i,t;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&d[i],&h[i]);
    }
    //d[0]=0,h[0]=0;
    int f=0,ans=d[1]-1+h[1],s,cnt;
    for(i=2;i<=m;i++)
    {
        t=d[i]-d[i-1];
        s=h[i]-h[i-1];
        if(t<abs(s))
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        cnt=(t+s)/2;
        ans=max(ans,cnt+h[i-1]);
    }
    cnt=n-d[m]+h[m];
    ans=max(ans,cnt);
    printf("%d\n",ans);
    return 0;
}