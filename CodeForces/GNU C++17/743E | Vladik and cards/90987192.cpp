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
vi g[10];
int a[1010],dp[1010][260],vis[1010][260],m=256,ans=0,n,mark=0;
int dfs(int x,int y,int z)
{
    if(vis[x][y]) return dp[x][y];
    vis[x][y]=1;
    if(x>n)
    {
        if(y==m-1)
        {
            return dp[x][y]=0;
        }
        else
        {
            return dp[x][y]=-inf;
        }
    }
    int ret=-inf,pos;
    if(!((y>>a[x]-1)&1))
    {
        pos=lower_bound(g[a[x]].begin(),g[a[x]].end(),x)-g[a[x]].begin();
        if(pos+z-1<g[a[x]].size())
        {
            ret=max(ret,z+dfs(g[a[x]][pos+z-1]+1,y|(1<<(a[x]-1)),z));
        }
        if(pos+z<g[a[x]].size())
        {
            ret=max(ret,z+1+dfs(g[a[x]][pos+z]+1,y|(1<<(a[x]-1)),z));
        }
    }
    dp[x][y]=max(ret,dfs(x+1,y,z));
    return dp[x][y];
}
 
 
int fun(int x)
{
    mem(dp,-inf);
    mem(vis,0);
    int ret=-inf;
    ret=max(ret,dfs(1,0,x));
    ans=max(ret,ans);
    if(ret>=0)
        return 1;
    else
        return 0;
}
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in();
    for(int i=1;i<=n;i++)
    {
        a[i]=in();
        g[a[i]].pb(i);
        if(!((mark>>a[i])&1))
        {
            mark|=(1<<a[i]);
            ans++;
        }
    }
    int lo=1,hi=n/8;
    while(lo<=hi)
    {
        int mid=(lo+hi)>>1;
        if(fun(mid))
            lo=mid+1;
        else
            hi=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
 