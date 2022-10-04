#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int dp[1000010],p[1000010];
 
main()
{
    memset(dp,0,sizeof dp);
    int n,i,t,a,b,ma=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        dp[a]=1;
        p[a]=b;
    }
    for(i=0;i<1000010;i++)
    {
        dp[i]+=((i-p[i]-1<0)?0:dp[i-p[i]-1]);
        ma=max(ma,dp[i]);
    }
    printf("%d\n",n-ma);
    return 0;
}