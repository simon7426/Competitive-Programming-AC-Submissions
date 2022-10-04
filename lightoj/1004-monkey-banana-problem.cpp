#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int dp[210][105],a[210][105];
main()
{
    int tcc,tc,n,i,j,t;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
                scanf("%d",&a[i][j]);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
                scanf("%d",&a[n+i][j]);
        }
        dp[0][0]=a[0][0];
        for(i=1;i<n;i++)
            dp[i][0]+=dp[i-1][0]+a[i][0];
        for(i=1;i<n;i++)
        {
            for(j=1;j<=i;j++)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
        }
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1-i;j++){
                dp[n+i][j]=max(dp[n+i-1][j],dp[n+i-1][j+1])+a[n+i][j];
            //printf("%d %d %d\n",n+i,j,dp[i][j]);
            }
        }
        printf("Case %d: %d\n",tc,dp[n+n-2][0]);
    }
    return 0;
}
