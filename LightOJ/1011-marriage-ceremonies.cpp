#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

inline bool checkb(ll n, int i) { return n&(1LL<<i); }
inline ll setb(ll n, int i) { return n|(1LL<<i);; }
inline ll resetb(ll n, int i) { return n&(~(1LL<<i)); }

int n,dp[16][1<<16],v[16][16];

int f(int x,int k)
{
    if(x>=n) return 0;
    if(dp[x][k]!=-1) return dp[x][k];
    for(int i=0;i<n;i++)
    {
        if(!checkb(k,i)) dp[x][k]=max(dp[x][k],v[x][i]+f(x+1,setb(k,i)));
    }
    return dp[x][k];
}

main()
{
    int tc,tcc,i,j;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&v[i][j]);
        }
        printf("Case %d: %d\n",tc,f(0,0));
    }
    return 0;
}
