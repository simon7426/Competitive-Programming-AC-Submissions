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
//inline double ind() { double x;scanf("%lf",&x);return x;}
 
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
 
const int maxn=5001;
const int maxm=21111;
int node,src,des,edge;
int ver[maxm],flow[maxm],nxt[maxm];
int head[maxn],work[maxn],dis[maxn],q[maxn];
 
void init(int nodee,int srcc,int dest)
{
    node=nodee;
    src=srcc;
    des=dest;
    for(int i=0;i<node;i++) head[i]=-1;
    edge=0;
}
 
void add_edge(int frm,int to,int flw)
{
    ver[edge]=to,flow[edge]=flw,nxt[edge]=head[frm],head[frm]=edge++;
    ver[edge]=frm,flow[edge]=0,nxt[edge]=head[to],head[to]=edge++;
}
 
bool bfs()
{
    int i,u,v,l,r=0;
    for(int i=0;i<node;i++) dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0;l<r;l++)
    {
        for(i=head[u=q[l]];i>=0;i=nxt[i])
            if(flow[i]&&dis[v=ver[i]]<0)
        {
            dis[q[r++]=v]=dis[u]+1;
            if(v==des) return 1;
        }
    }
    return 0;
}
 
bool dfs(int u,int ex)
{
    if(u==des) return ex;
    for(int &i=work[u],v,tmp;i>=0;i=nxt[i])
    {
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=dfs(v,min(ex,flow[i])))>0)
        {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    }
    return 0;
}
 
int fast_dinic()
{
    int i,res=0,del;
    while(bfs())
    {
        for(i=0;i<node;i++) work[i]=head[i];
        while(del=dfs(src,inf)) res+=del;
    }
    return res;
}
 
int a[205],prime[20010];
int n,cnt=0,vis[205];
vi ans[100];
 
void dfs2(int x,int pa,int ori)
{
    //printf("%d %d %d\n",x,pa,ori);
    vis[x]=1;
    ans[cnt].pb(x);
    for(int e=head[x];e!=-1;e=nxt[e])
    {
        int v=ver[e];
        if(v==src||v==des||v==pa||vis[v]) continue;
        //printf("%d\n",v);
        if(flow[e^ori]==0)
        {
            dfs2(v,x,ori^1);
        }
    }
}
 
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in();
    init(n+2,0,n+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=in();
        if(a[i]&1)
        {
            add_edge(src,i,2);
        }
        else
        {
            add_edge(i,des,2);
        }
    }
    for(int i=2;i<150;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<20010;j+=i)
                prime[j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]&1 && i==j) continue;
                if(prime[a[i]+a[j]]==0)
                    add_edge(i,j,1);
            }
        }
    }
    int an=fast_dinic();
    if(an!=n)
    {
        printf("Impossible\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1 && vis[i]==0)
        {
            cnt++;
            dfs2(i,-1,0);
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
 
 