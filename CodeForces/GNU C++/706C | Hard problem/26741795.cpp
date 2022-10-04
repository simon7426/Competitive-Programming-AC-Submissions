#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 1e5+2;
const ll inf = 1e18;
void rev(char *sr,const char *s)
{
    int l;
    l=strlen(s);
    for(int i=0;i<l;i++)
        sr[i]=s[l-i-1];
    sr[l]=0;
}
char s[N],sr[N],ps[N],pr[N];
main()
{
    ll n,i,t,dp[N][2];
    scanf("%I64d",&n);
    int a[N];
    for(i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    getchar();
    gets(ps);
    //puts(ps);
    rev(pr,ps);
    //puts(pr);
    dp[0][0]=0;
    dp[0][1]=a[0];
    for(i=1;i<n;i++)
    {
        gets(s);
        rev(sr,s);
        dp[i][0]=dp[i][1]=inf;
        if(strcmp(ps,s)<=0) dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if(strcmp(ps,sr)<=0)dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
        if(strcmp(pr,s)<=0) dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if(strcmp(pr,sr)<=0) dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
        strcpy(ps,s);
        strcpy(pr,sr);
        //printf("%I64d %I64d\n",dp[i][0],dp[i][1]);
    }
    ll ans=min(dp[n-1][0],dp[n-1][1]);
    (ans==inf)?printf("-1\n"):printf("%I64d\n",ans);
    return 0;
}