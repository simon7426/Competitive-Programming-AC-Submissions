#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,ll> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
const ll inf=1e14;
vii g[200010];
int vis[20010],p[200010];
int n,m,s,t;
vl dis;
 
void printpath(int x)
{
    if(x==1)
    {
        printf("%d ",x);
        return;
    }
    printpath(p[x]);
    printf("%d ",x);
}
 
void dij(int x)
{
    dis[x]=0;
    priority_queue<pii> pq;
    pq.push(pii(0,x));
    while(!pq.empty())
    {
        pii y=pq.top();
        pq.pop();
        int d=y.first*-1;
        int u=y.second;
        if(d>dis[u]) continue;
        for(int j=0;j<g[u].size();j++)
        {
            pii v=g[u][j];
            if(dis[u]+(ll)v.first<dis[v.second])
            {
                p[v.second]=u;
                dis[v.second]=dis[u]+(ll)v.first;
                pq.push(pii(dis[v.second]*-1,v.second));
            }
        }
    }
 
}
 
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,tcc,i,u,v,w;
    memset(vis,0,sizeof vis);
    scanf("%d %d ",&n,&m);
    for(i=0;i<m;i++)
    {
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(make_pair(w,v));
            g[v].push_back(make_pair(w,u));
    }
    dis.assign(n+2,inf);
    memset(p,0,sizeof p);
    dij(1);
    if(dis[n]==inf)
    {
        printf("-1\n");
        return 0;
    }
    printpath(n);
    printf("\n");
    return 0;
}
 
 