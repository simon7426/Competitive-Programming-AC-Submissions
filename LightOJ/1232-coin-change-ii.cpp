
#include<bits/stdc++.h>

using namespace std;

#define MOD 100000007
typedef long long ll;
ll dp[10008],c[105],n,k;

main()
{
    int tc,tcc,i,j;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(dp,0,sizeof dp);
        memset(c,0,sizeof c);
        dp[0]=1;
        //memset(x,0,sizeof x);
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&c[i]);
        for(i=0;i<n;i++)
        {
            for(j=1;j<=k;j++)
                if(c[i]<=j)
                dp[j]=dp[j]%MOD+dp[j-c[i]]%MOD;
        }

        printf("Case %d: %lld\n",tc,dp[k]%MOD);
    }
}
