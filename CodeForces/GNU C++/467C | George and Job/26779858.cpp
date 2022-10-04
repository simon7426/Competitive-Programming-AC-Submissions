#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mx 5005
ll dp[mx][mx];
main()
{
    ll a[mx];
    memset(dp,0,sizeof dp);
    memset(a,0,sizeof a);
    int n,m,k,i,j;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        {cin>>a[i];
        a[i]+=a[i-1];}
    for(i=m;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]-a[i-m]+a[i]);
        }
    }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dp[n][k]<<endl;
    return 0;
}