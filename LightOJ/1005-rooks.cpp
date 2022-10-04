#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[35][35];
int n,k;
main()
{
    int tcc,tc,i,j;
    for(i=1;i<=30;i++)
    {
        dp[i][0]=1;
        dp[i][1]=i*i;
    }
    for(i=2;i<=30;i++)
    {
        for(j=2;j<=i;j++)
            dp[i][j]=(dp[i][1]*dp[i-1][j-1])/j;
    }
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        scanf("%d %d",&n,&k);
        printf("Case %d: %lld\n",tc,(n<k)?0LL:dp[n][k]);
    }
    return 0;
}
