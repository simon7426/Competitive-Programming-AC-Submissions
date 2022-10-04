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
 
#define mp make_pair
 
vii g[105];
int vis[105],m,n,a,b,c;
bool f;
bool dfs(int x,int col,int dst)
{
    vis[x]=1;
    if(x==dst) return true;
    for(int i=0;i<g[x].size();i++)
    {
        pii y=g[x][i];
        if(y.second==col&&vis[y.first]==0)
            if(dfs(y.first,col,dst)) return true;
    }
    return false;
}
main()
{
    int q,i,x,cnt;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back(mp(b,c));
        g[b].push_back(mp(a,c) );
    }
    scanf("%d",&q);
    for(x=0;x<q;x++)
    {
        cnt=0;
        scanf("%d %d",&a,&b);
        for(i=1;i<=100;i++)
        {
            memset(vis,0,sizeof vis);
            vis[a]=1;
            if(dfs(a,i,b)) ++cnt;
        }
        printf("%d\n",cnt);
    }
}