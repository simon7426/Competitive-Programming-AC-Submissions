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
vi g[200010];
set<int> s[200010];
int dis[200010],fa[200010];
int fl=0,rt;
void dfs(int x,int pa,int dep)
{
    dis[x]=dep;
    fa[x]=pa;
    for(int i=0;i<g[x].size();i++)
    {
        if(g[x][i]==pa) continue;
        dfs(g[x][i],x,dep+1);
    }
}
 
int dfs2(int x,int pa)
{
    if(fl) return -1;
    if(x!=rt && g[x].size()==1) return 0;
    for(int i=0;i<g[x].size();i++)
    {
        if(g[x][i]==pa)continue;
        s[x].insert(dfs2(g[x][i],x)+1);
        if(x!=rt && s[x].size()>1)
        {
            fl=1;
            return -1;
        }
    }
    return *s[x].begin();
}
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),x,y;
    for(int i=1;i<n;i++)
    {
        x=in(),y=in();
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,0,0);
    int tmp=1,tmpdis;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>dis[tmp])
            tmp=i;
    }
    dfs(tmp,0,0);
    tmp=1;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>dis[tmp])
        {
            tmp=i;
        }
    }
    tmpdis=dis[tmp];
    rt=tmp;
    for(int i=1;i<=tmpdis/2;i++)
        rt=fa[rt];
    dfs2(rt,-1);
    if(s[rt].size()>2) fl=1;
    if(fl)
    {
        printf("-1\n");
        return 0;
    }
    int ans=0;
    for(auto it=s[rt].begin();it!=s[rt].end();it++)
    {
        ans+=*it;
    }
    while(ans%2==0) ans/=2;
    printf("%d\n",ans);
}
 