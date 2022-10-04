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
const int mx=105;
int cap[mx][mx];
int flowpass[mx][mx];
int curcap[mx];
vi g[mx];
int p[mx];

int bfs(int s,int t)
{
    mem(p,-1);
    mem(curcap,0);
    queue<int> q;
    p[s]=-2;
    q.push(s);
    curcap[s]=1e9;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(p[v]==-1)
            {

                if(cap[u][v]-flowpass[u][v]>0)
                {
                    p[v]=u;
                    curcap[v]=min(curcap[u],cap[u][v]-flowpass[u][v]);
                    if(v==t) return curcap[v];
                    q.push(v);
                }
            }
        }
    }
    return 0;
}

int maxflow(int s,int t)
{
    int mf=0;
    while(1)
    {
        int fl=bfs(s,t);
        if(fl==0)
            break;
        int u=t;
        mf+=fl;
        while(u!=s)
        {
            int v=p[u];
            flowpass[v][u]+=fl;
            flowpass[u][v]-=fl;
            u=v;
        }
    }
    return mf;
}

int main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n,m,i,j,s,t,u,v,w;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&s,&t);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        //cout<<u<<" "<<v<<" "<<w<<endl;
        cap[u][v]=w;
        g[u].pb(v);
        g[v].pb(u);
    }
    int mf=maxflow(s,t);
    printf("%d\n",mf);
    return 0;
}

