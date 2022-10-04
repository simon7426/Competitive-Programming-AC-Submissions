#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll dp[1005][1005];
const int mod=1e9+7;
main()
{
    int i,j;
    dp[0][0]=1;
    for(i=1;i<=1000;i++)
        dp[i][0]=1,dp[i][i]=1;
    for(i=2;i<=1000;i++)
    {
        for(j=1;j<i;j++)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
    }
    ll n,t=0,ans=1,a[1010];
    scanf("%I64d",&n);
    scanf("%I64d",&a[0]);
    t=a[0];
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        t+=a[i];
        ans=(ans*dp[t-1][a[i]-1])%mod;
    }
    printf("%I64d\n",ans);
}