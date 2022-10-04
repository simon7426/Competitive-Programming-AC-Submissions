#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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
 
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
 
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
vi g[10010],ans;
int n,m;
int u[10010],v[10010],dis[10010],fa[10010],vis[10010];
int cod = 0,cev = 0;
int nodd[10010],neve[10010];
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(!vis[g[x][i]])
        {
            fa[g[x][i]]=x;
            dis[g[x][i]]=dis[x]+1;
            dfs(g[x][i]);
        }
        else if(y!=fa[x] && dis[y]<dis[x])
        {
            int len = dis[x]-dis[y]+1;
            if(len & 1)
            {
                cod++;
                nodd[x]++,nodd[y]--;
            }
            else
            {
                cev++;
                neve[x]++,neve[y]--;
            }
        }
    }
 
}
 
void dfs2(int x)
{
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(!vis[y])
        {
            dfs2(y);
            nodd[x]+=nodd[y];
            neve[x]+=neve[y];
        }
    }
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
        u[i]=in(),v[i]=in();
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    mem(vis,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i);
    }
    mem(vis,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs2(i);
        }
    }
 
    for(int i=0;i<m;i++)
    {
        if(dis[u[i]]<dis[v[i]]) 
            swap(u[i],v[i]);
        
        if(cod==0||(cod==1 && dis[u[i]]!=dis[v[i]]+1 && (dis[u[i]]-dis[v[i]]+1)&1) || (dis[u[i]]==dis[v[i]]+1 && nodd[u[i]]==cod && neve[u[i]]==0))
        {
            ans.pb(i);
        }
    }
    int res = ans.size();
    printf("%d\n",res);
    for(int i=0;i<res;i++)
    {
        printf("%d ",ans[i]+1);
    }
    printf("\n");
    return 0;
 
}