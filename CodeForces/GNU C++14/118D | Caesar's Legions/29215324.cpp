#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int mod=1e8;
int dp[102][102][11][11];
int in,ca,in1,ca1;
 
int f(int n,int m,int n1,int m1)
{
    if(n==in&&ca==m) return 1;
    if(dp[n][m][n1][m1]!=-1) return dp[n][m][n1][m1];
    int x=0,y=0;
    if(n<in&&n1<in1)
        x=f(n+1,m,n1+1,0)%mod;
    if(m<ca&&m1<ca1)
        y=f(n,m+1,0,m1+1)%mod;
    return dp[n][m][n1][m1]=(x+y)%mod;
}
main()
{
    int n,i,t;
    scanf("%d %d %d %d",&in,&ca,&in1,&ca1);
    memset(dp,-1,sizeof dp);
    printf("%d\n",f(0,0,0,0));
}