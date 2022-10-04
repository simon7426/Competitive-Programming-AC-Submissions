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
vii g[200010];
int vis[200010],wei[200010],cnt[200010];
int n;
int dfs(int x)
{
    vis[x]=1;
    wei[x]=0;
    pii j;
    for(int i=0;i<g[x].size();i++)
    {
        j=g[x][i];
        if(vis[j.ff]==0)
        {
            wei[x]+=j.ss;
            dfs(j.ff);
            wei[x]+=wei[j.ff];
        }
    }
}
int dfs1(int x)
{
    vis[x]=1;
    pii j;
    for(int i=0;i<g[x].size();i++)
    {
        j=g[x][i];
        if(vis[j.ff]==0)
        {
            if(j.ss==0)
            {
                cnt[j.ff]=cnt[x]+1;
                dfs1(j.ff);
            }
            else
            {
                cnt[j.ff]=cnt[x]-1;
                dfs1(j.ff);
            }
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
    int i,a,b;
    for(i=0;i<n-1;i++)
    {
        a=in(),b=in();
        g[a].pb(mp(b,0));
        g[b].pb(mp(a,1));
    }
    mem(vis,0);
    dfs(1);
    mem(vis,0);
    cnt[1]=wei[1];
    dfs1(1);
    //for(i=1;i<=n;i++) printf("%d ",cnt[i]);
    int ans=INT_MAX;
    for(i=1;i<=n;i++)
        ans=min(ans,cnt[i]);
    printf("%d\n",ans);
    for(i=1;i<=n;i++)
        if(cnt[i]==ans)
            printf("%d ",i);
    printf("\n");
}

