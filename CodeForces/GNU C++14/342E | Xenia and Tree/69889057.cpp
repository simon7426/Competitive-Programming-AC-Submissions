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
 
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'
 
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)
 
#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; ///4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};///8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; ///Hexagonal Direction
 
inline int in() { int x; scanf("%d", &x); return x; }
inline ll inl() { ll x;scanf("%I64d",&x); return x;}
inline double ind() { double x;scanf("%lf",&x);return x;}
 
int gcd(int a,int b) { return b==0 ? a:gcd(b,a%b);}
int power( int x, int n)
{
    if(n==0)return 1;
    else if(n%2==0)
    {
        int y=power(x,n/2);
        return y*y;
    }
    else
        return x*power(x,n-1);
}
//abcdefghijklmnopqrstuvwxyz//
vi g[100010];
int sz[100010],center[100010],dis[20][100010],level[100010],par[100010];
int ans[100010];
void dfs(int u,int p)
{
    sz[u]=1;
    for(int &v:g[u])
    {
        if(v!=p && !center[v])
        {
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
}
int find_center(int u,int p,int si)
{
    for(int &v:g[u])
    {
        if(v!=p && !center[v] && sz[v]>si/2)
        {
            return find_center(v,u,si);
        }
    }
    return u;
}
void find_dis(int s,int d)
{
    queue<pii> q;
    q.push({s,-1});
    dis[d][s]=0;
    while(!q.empty())
    {
        int u=q.front().ff,p=q.front().ss;
        q.pop();
        for(int &v:g[u])
        {
            if(v!=p && !center[v])
            {
                dis[d][v]=dis[d][u]+1;
                q.push({v,u});
            }
        }
    }
}
 
void centdecompose(int u,int p,int d)
{
    dfs(u,-1);
    int c=find_center(u,-1,sz[u]);
    center[c]=1,level[c]=d,par[c]=p;
    find_dis(c,d);
    ans[c]=inf;
    for(int &v:g[c])
    {
        if(!center[v])
        {
            centdecompose(v,c,d+1);
        }
    }
}
int query(int u)
{
    int x=u,res=inf;
    while(x!=-1)
    {
        res=min(res,dis[level[x]][u]+ans[x]);
        x=par[x];
    }
    return res;
}
void update(int u)
{
    int x=u;
    while(x!=-1)
    {
        ans[x]=min(ans[x],dis[level[x]][u]);
        x=par[x];
    }
}
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    centdecompose(1,-1,0);
    update(1);
    while(m--)
    {
        scanf("%d%d",&v,&u);
        if(v==1) update(u);
        else
        {
            printf("%d\n",query(u));
        }
    }
    return 0;
}
 