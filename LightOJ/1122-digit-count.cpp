#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,k;
ll dp[105][105];
int a[15];

int f(int m,int i)
{
    if(m==1) return 1;
    if(dp[m][i]!=-1) return dp[m][i];
    ll cnt=0;
    for(int j=0;j<n;j++)
    {
        if(abs(a[i]-a[j])<=2)
            cnt+=f(m-1,j);
    }
    return dp[m][i]=cnt;
}

main()
{
    int tc,tcc,i;
    ll t=0;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(dp,-1,sizeof dp);
        t=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            t+=f(k,i);
        printf("Case %d: %d\n",tc,t);
    }
    return 0;
}
