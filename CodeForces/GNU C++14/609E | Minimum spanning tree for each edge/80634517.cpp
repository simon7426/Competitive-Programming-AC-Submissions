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
struct node
{
    int id,x,y,w;
    bool operator < (const node &r) const
    {
        return w<r.w;
    }
}a[200010],b[200010];
struct edge
{
    int v,next,w;
}ed[400010];
int head[200010];
int n,m,pa[200010],id[200010],k=0;
int fa[200010][20],dis[200010][20],dep[200010];
int findp(int x)
{
    if(pa[x]==x) return x;
    return pa[x]=findp(pa[x]);
}
void addedge(int u,int v,int w)
{
    ed[++k].v=v;
    ed[k].w=w;
    ed[k].next=head[u];
    head[u]=k;
    return;
}
void dfs(int u,int pre,int w)
{
    fa[u][0]=pre;
    dep[u]=dep[pre]+1;
    dis[u][0]=w;
    for(int i=1;i<20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=1;i<20;i++) dis[u][i]=max(dis[u][i-1],dis[fa[u][i-1]][i-1]);
    for(int i=head[u];i;i=ed[i].next)
    {
        if(ed[i].v==pre) continue;
        dfs(ed[i].v,u,ed[i].w);
    }
}
int lca(int u,int v)
{
    if(dep[u]>dep[v])swap(u,v);
    int h=dep[v]-dep[u];
    int ret=-1;
    for(int i=19;i>=0;i--)
    {
        if(h&(1<<i))
        {
            ret=max(ret,dis[v][i]);
            v=fa[v][i];
        }
    }
    if(u==v) return ret;
    for(int i=19;i>=0;i--)
    {
        if(fa[u][i]==fa[v][i])continue;
        ret=max(max(ret,dis[u][i]),dis[v][i]);
        u=fa[u][i];
        v=fa[v][i];
    }
    return max(ret,max(dis[u][0],dis[v][0]));
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in();
    for(int i=0;i<m;i++)
    {
        a[i].id=i;
        a[i].x=in();
        a[i].y=in();
        a[i].w=in();
        b[i]=a[i];
    }
    sort(a,a+m);
    for(int i=1;i<=n;i++) pa[i]=i;
    int cnt=0,x,y,w;
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        x=findp(a[i].x);
        y=findp(a[i].y);
        if(x!=y)
        {
            if(x>y) swap(x,y);
            pa[x]=y;
            ans+=a[i].w;
            cnt++;
            id[a[i].id]=1;
            addedge(a[i].x,a[i].y,a[i].w);
            addedge(a[i].y,a[i].x,a[i].w);
        }
        if(cnt==n-1) break;
    }
    dfs(1,0,0);
    int sm;
    for(int i=0;i<m;i++)
    {
        if(id[i]==1)
        {
            printf("%I64d\n",ans);
        }
        else
        {
           sm=lca(b[i].x,b[i].y);
           printf("%I64d\n",ans-sm+b[i].w);
        }
    }
}