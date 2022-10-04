//Lightoj 1222
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
struct node
{
    int to;
    int cap;
    int cost;
    int next;
}edge[10010];
int source,sink;
int cnt;
int head[1010];
int vis[1010];
int num[1010];
int dep[1010];
int pre[1010];
int rec[1010];
int dis[1010];
const int hinf=0x3f3f3f3f;

void init()
{
    mem(head,-1);
    mem(pre,-1);
    mem(rec,-1);
    cnt = 0;
    return;
}

void add(int u,int v,int cap,int cost)
{
    edge[cnt].to=v;
    edge[cnt].cap=cap;
    edge[cnt].cost=cost;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].to=u;
    edge[cnt].cap=0;
    edge[cnt].cost=-cost;
    edge[cnt].next=head[v];
    head[v]=cnt++;
    return;
}

bool spfa()
{
    queue<int> q;
    q.push(source);
    mem(dis,hinf);
    mem(vis,0);
    dis[source]=0;
    vis[source]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        vis[node]=0;
        for(int i=head[node];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>0&&dis[v]>dis[node]+edge[i].cost)
            {
                dis[v]=dis[node]+edge[i].cost;
                rec[v]=i;
                pre[v]=node;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    //printf("%d\n",dis[sink]);
    return dis[sink]!=hinf;
}

int mcmf()
{
    int maxflow=0;
    int mincost=0;
    while(spfa())
    {
        int node=sink;
        int flow=hinf;
        while(node!=source)
        {
            flow=min(flow,edge[rec[node]].cap);
            node=pre[node];
        }
        node=sink;
        while(node!=source)
        {
            mincost+=flow*edge[rec[node]].cost;
            edge[rec[node]].cap-=flow;
            edge[rec[node]^1].cap+=flow;
            node=pre[node];
        }
    }
    return -mincost;
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        init();
        int n=in();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int x=in();
                add(i,j+n,1,-x);
            }
        }
        source=0;
        sink=2*n+1;
        for(int i=1;i<=n;i++)
        {
            add(source,i,1,0);
        }
        for(int i=1;i<=n;i++)
        {
            add(i+n,sink,1,0);
        }
        printf("Case %d: %d\n",tc,mcmf());
    }
}
/*
2
2
4 3
3 1
3
1 4 5
5 7 6
5 8 8
*/
