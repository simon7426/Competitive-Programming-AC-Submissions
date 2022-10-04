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
const int mx=405000;
const int mlg=22;

int n,qn;
vi g[mx];
int dp[mx][mlg];
int tin[mx],tout[mx];
int timer;

int a[mx];
int x,y,z;

void dfs(int v,int par=1)
{
    timer++;
    tin[v]=timer;
    dp[v][0]=par;
    for(int i=1;i<mlg;i++)
        dp[v][i]=dp[dp[v][i-1]][i-1];
    for(int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if(to!=par)
            dfs(to,v);
    }
    timer++;
    tout[v]=timer;
}

bool isparent(int a,int b)
{
    return tin[a]<=tin[b]&&tout[a]>=tout[b];
}

int lca(int a,int b)
{
    if(isparent(a,b))
        return a;
    if(isparent(b,a))
        return b;
    for(int i=mlg-1;i>=0;i--)
    {
        if(!isparent(dp[a][i],b))
            a=dp[a][i];
    }
    return dp[a][0];
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),qn=in();
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        u=in(),v=in();
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    for(int i=1;i<=qn;i++)
    {
        u=in(),v=in();
        x=lca(u,v);
        printf("%d\n",x);
    }
}

