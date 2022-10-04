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
struct edge
{
    int des,gc,lc;
};
vector<edge> g[105];
vi check;
int vis[105],val[105];
bool dfs(int x)
{
    //printf("%d\n",x);
    if(vis[x]) return true;
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        edge tmp=g[x][i];
        if(tmp.lc%val[x]!=0) return false;
        int y=tmp.lc/val[x]*tmp.gc;
        if(gcd(val[x],y)!=tmp.gc) return false;
        if(vis[tmp.des]&&val[tmp.des]!=y) return false;
        val[tmp.des]=y;
        if(!dfs(tmp.des)) return false;
    }
    return true;
}
bool lol(int x)
{
    //printf("%d\n",x);
    for(int i=g[x][0].gc;i<=g[x][0].lc;i++)
    {
        mem(vis,0);
        val[x]=i;
        if(dfs(x)) return true;
    }
    return false;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),m=in(),ma=1e8,mi,sta;
    for(int i=0;i<m;i++)
    {
        int x=in();
        int y=in();
        int a=in();
        int b=in();
        edge yy={y,a,b};
        edge xx={x,a,b};
        g[x].pb(yy);
        g[y].pb(xx);
    }
    mem(val,0);
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==0||val[i]) continue;
        else if(!lol(i))
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        if(val[i]==0) val[i]=1;
        printf("%d ",val[i]);
    }
    return 0;
}