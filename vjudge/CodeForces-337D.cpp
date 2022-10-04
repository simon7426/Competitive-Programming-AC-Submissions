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
int n,m,d;
vi g[100010];
vii ch[100010];
int ev[100010],vis[100010],up[100010],dn[100010];
void dfs(int x)
{
    vis[x]=1;
    if(ev[x]==1) dn[x]=0;
    int i,j;
    for(i=0;i<g[x].size();i++)
    {
        j=g[x][i];
        if(vis[j]) continue;
        dfs(j);
        dn[x]=max(dn[x],dn[j]+1);
        ch[x].pb(mp(dn[j],j));
    }
    sort(ch[x].begin(),ch[x].end());
    reverse(ch[x].begin(),ch[x].end());
}

void dfs1(int x)
{
    vis[x]=1;
    if(ev[x]) up[x]=max(up[x],0);
    int i,j;
    for(i=0;i<g[x].size();i++)
    {
        j=g[x][i];
        if(vis[j])continue;
        if(ev[j])up[j]=0;
        up[j]=max(up[j],up[x]+1);
        if(ch[x].size()!=1)
        {
            if(ch[x][0].ss==j) up[j]=max(up[j],ch[x][1].ff+2);
            else up[j]=max(up[j],ch[x][0].ff+2);
        }
        dfs1(j);
    }
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in(),d=in();
    int i,j,t,u,v;
    for(i=0;i<=n;i++) dn[i]=up[i]=INT_MIN;
    for(i=0;i<m;i++)
    {
        t=in();
        ev[t]=1;
    }
    for(i=0;i<n-1;i++)
    {
        u=in(),v=in();
        g[u].pb(v);
        g[v].pb(u);
    }
    mem(vis,0);
    dfs(1);
    mem(vis,0);
    dfs1(1);
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(max(dn[i],up[i])<=d) ans++;
    }
    printf("%d\n",ans);
}

