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
vi g[100010],grev[100010];
int n,m;
int f1[100010],f2[100010];
int a[100010],vis[100010];
void dfs1(int x)
{
    vis[x]=1;
    f1[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        if(!vis[g[x][i]])
            dfs1(g[x][i]);
    }
}
void dfs2(int x)
{
    //printf("%d %d\n",x,a[x]);
    vis[x]=1;
    f2[x]=1;
    if(a[x]==1) return;
    for(int i=0;i<grev[x].size();i++)
    {
        //printf("%d ",g[x][i]);
        if(!vis[grev[x][i]])
            dfs2(grev[x][i]);
    }
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in();
    int i,j,x,y;
    for(i=1;i<=n;i++) a[i]=in();
    for(i=0;i<m;i++)
    {
        x=in(),y=in();
        g[x].pb(y);
        grev[y].pb(x);
    }
    mem(vis,0);
    for(i=1;i<=n;i++)
    {
        if(a[i]==1&&!vis[i]) dfs1(i);
    }
    //printf("here\n");
    mem(vis,0);
    for(i=1;i<=n;i++)
    {
        if(a[i]==2&&!vis[i])dfs2(i);
    }
    //printf("here\n");
    for(i=1;i<=n;i++)
    {
        if(f1[i]&&f2[i])printf("1\n");
        else printf("0\n");
    }
    return 0;
}
 