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
 
vi g1[100010],g2[100010],st,sc[100010];
int c[100010],n,m,vis[100010],z=0;
map<int,int> mm;
 
void scc(int u,int p)
{
    vis[u]=1;
    vi nn;
    int v;
    if(p==1) nn=g1[u];
    else nn=g2[u];
    for(int j=0;j<nn.size();j++)
    {
        v=nn[j];
        if(!vis[v])
            scc(v,p);
    }
    st.pb(u);
    if(p==2) sc[z].pb(u);
}
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int x,y;
    n=in();
    int i,j;
    for(i=0;i<n;i++)
        c[i]=in();
    m=in();
    for(i=0;i<m;i++)
    {
        x=in();
        y=in();
        g1[x].pb(y);
        g2[y].pb(x);
    }
    mem(vis,0);
 
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            scc(i,1);
    }
    int numscc=0;
    mem(vis,0);
    for(i=n-1;i>=0;i--)
    {
        if(!vis[st[i]])
        {
            numscc++;
            scc(st[i],2);
            z++;
        }
    }
    ll ans=0,w=1,q;
 
    for(i=0;i<numscc;i++)
    {
        mm.clear();
        for(j=0;j<sc[i].size();j++)
            {
                q=sc[i][j];
                --q;
                mm[c[q]]++;
            }
        auto it=mm.begin();
        //cout<<it->first<<" "<<it->second<<" "<<w<<endl;
        ans+=it->first;
        w=((w%MOD)*(it->second%MOD))%MOD;
 
       // cout<<w<<" "<<ans<<endl;
    }
    printf("%I64d %I64d\n",ans,w);
    return 0;
}
 