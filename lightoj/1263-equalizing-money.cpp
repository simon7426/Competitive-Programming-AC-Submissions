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
int n,m,t,a[1010],vis[1010],cnt,mon;
vi g[1010];
set<int> s;
void dfs(int x)
{
    if(vis[x]) return;
    int i,j;
    vis[x]=1;
    cnt++;
    mon+=a[x];
    for(i=0;i<g[x].size();i++)
    {
        j=g[x][i];
        if(vis[j])continue;
        dfs(j);
    }
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in(),tc;
    for(tc=1;tc<=tcc;tc++)
    {
        int i,j,u,v;
        for(i=0;i<1010;i++) g[i].clear();
        mem(vis,0);
        mem(a,0);
        s.clear();
        n=in(),m=in();
        for(i=1;i<=n;i++)
            a[i]=in();
        for(i=0;i<m;i++)
        {
            u=in(),v=in();
            g[u].pb(v);
            g[v].pb(u);
        }
        int f=1;
        for(i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            cnt=0;
            mon=0;
            dfs(i);
            if(mon%cnt)
            {
                f=0;
                break;
            }
            s.insert(mon/cnt);
        }
        printf("Case %d: ",tc);
        if(f==1&&s.size()==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

