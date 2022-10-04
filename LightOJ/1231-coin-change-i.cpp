#include<bits/stdc++.h>

using namespace std;

#define MOD 100000007
typedef long long ll;
int dp[55][1008],c[51],x[51],n,k;

ll f(int pos,int v)
{
    ll ans=0;
    if(v==k) return 1;
    if(pos==n) return 0;


    if(dp[pos][v]!=-1) return dp[pos][v];
    for(int j=0;j<=x[pos]&&v+(c[pos]*j)<=k;j++)
        {
        ans+=f(pos+1,v+(c[pos]*j));
        ans%=MOD;
        }
       // printf("%d %d %d\n",pos,v,ans);
   return dp[pos][v]=ans;
}

main()
{
    int tc,tcc,i,j;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(dp,-1,sizeof dp);
        memset(c,0,sizeof c);
        memset(x,0,sizeof x);
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&c[i]);
        for(i=0;i<n;i++)
            scanf("%d",&x[i]);
        printf("Case %d: %lld\n",tc,f(0,0));
    }
}
