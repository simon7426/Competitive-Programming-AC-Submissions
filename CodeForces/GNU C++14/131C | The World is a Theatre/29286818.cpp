#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll dp[32][32];
main()
{
    memset(dp,0,sizeof dp);
    int i,j,k,n=31;
    for(i=0;i<=n;i++)
    {
        dp[i][0]=1,dp[i][i]=1;
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    }
    /*for(i=1;i<15;i++)
    {
        for(j=0;j<=i;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    ll ans=0;
    int m,t,b,g;
    cin>>n>>m>>t;
    for(i=4;i<t;i++)
    {
        b=i;
        g=t-b;
        if(b>n||g>m) continue;
        //cout<<b<<" "<<g<<" "<<dp[n][b]<<" "<<dp[m][g]<<endl;
        ans+=dp[n][b]*dp[m][g];
    }
    cout<<ans<<endl;
}