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

//#define PB push_back
#define PB emplace_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

vii g[200010];
int vis[20010];
int n,m,s,t;
vi dis;

void dij(int x)
{
    dis[x]=0;
    priority_queue<pii> pq;
    pq.push(pii(0,x));
    while(!pq.empty())
    {
        pii y=pq.top();
        pq.pop();
        int d=y.first*-1;
        int u=y.second;
        if(d>dis[u]) continue;
        for(int j=0;j<g[u].size();j++)
        {
            pii v=g[u][j];
            if(dis[u]+v.first<dis[v.second])
            {
                dis[v.second]=dis[u]+v.first;
                pq.push(pii(dis[v.second]*-1,v.second));
            }
        }
    }

}

main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,tcc,i,u,v,w;
    scanf("%d",&tc);
    for(tcc=1;tcc<=tc;tcc++)
    {
        memset(vis,0,sizeof vis);
        for(i=0;i<20010;i++) g[i].clear();
        scanf("%d %d %d %d",&n,&m,&s,&t);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            g[u].PB(MP(w,v));
            g[v].PB(MP(w,u));
        }
       dis.assign(n,inf);
       dij(s);
       if(dis[t]!=inf)
            printf("Case #%d: %d\n",tcc,dis[t]);
        else
            printf("Case #%d: unreachable\n",tcc);

    }
    return 0;
}

