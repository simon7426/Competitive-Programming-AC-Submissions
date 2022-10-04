#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
char s[105];
int dp[105][105];

int f(int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) dp[i][j]=f(i+1,j-1);
    else dp[i][j]=1+min(f(i+1,j),f(i,j-1));
    return dp[i][j];
}

main()
{
    int tc,tcc,i,t;
    scanf("%d ",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%s",s);
        //puts(s);
        n=strlen(s);
        printf("Case %d: %d\n",tc,f(0,n-1));
    }
}
