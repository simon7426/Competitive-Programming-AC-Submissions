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

#define PB push_back
//#define PB emplace_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'

vi g[10010];
int vis[10010],n,m,indig[10010];
stack<int> st;

void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
   {
       if(vis[g[x][i]]==0)
        dfs(g[x][i]);
   }
   st.push(x);
}

void dfs2(int x)
{
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
   {
       if(vis[g[x][i]]==0)
        dfs(g[x][i]);
   }
}

main()
{
   int tc,tcc,i,j,u,v,cnt;
   scanf("%d",&tcc);
   for(tc=1;tc<=tcc;tc++)
   {
       for(i=0;i<10010;i++) g[i].clear();
       memset(vis,0,sizeof vis);
       cnt=0;
       scanf("%d %d",&n,&m);
       for(i=0;i<m;i++)
       {
           scanf("%d %d",&u,&v);
           g[u].PB(v);
       }
       cnt=0;
       for(i=1;i<=n;i++)
       {
           if(vis[i]==0)
           {
               dfs(i);
           }
       }
       memset(vis,0,sizeof vis);
       while(!st.empty())
       {
           u=st.top();
           st.pop();
           if(!vis[u])
           {
               cnt++;
               dfs2(u);
           }
       }
       printf("Case %d: %d\n",tc,cnt);
   }
}
