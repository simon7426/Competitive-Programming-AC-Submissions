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
//inline double ind() { double x;scanf("%lf",&x);return x;}

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

const int maxn=5001;
const int maxm=21111;
int node,src,des,edge;
int ver[maxm],flow[maxm],nxt[maxm];
int head[maxn],work[maxn],dis[maxn],q[maxn];

void init(int nodee,int srcc,int dest)
{
    node=nodee;
    src=srcc;
    des=dest;
    for(int i=0;i<node;i++) head[i]=-1;
    edge=0;
}

void add_edge(int frm,int to,int flw)
{
    ver[edge]=to,flow[edge]=flw,nxt[edge]=head[frm],head[frm]=edge++;
    ver[edge]=frm,flow[edge]=0,nxt[edge]=head[to],head[to]=edge++;
}

bool bfs()
{
    int i,u,v,l,r=0;
    for(int i=0;i<node;i++) dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0;l<r;l++)
    {
        for(i=head[u=q[l]];i>=0;i=nxt[i])
            if(flow[i]&&dis[v=ver[i]]<0)
        {
            dis[q[r++]=v]=dis[u]+1;
            if(v==des) return 1;
        }
    }
    return 0;
}

bool dfs(int u,int ex)
{
    if(u==des) return ex;
    for(int &i=work[u],v,tmp;i>=0;i=nxt[i])
    {
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=dfs(v,min(ex,flow[i])))>0)
        {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    }
    return 0;
}

int fast_dinic()
{
    int i,res=0,del;
    while(bfs())
    {
        for(i=0;i<node;i++) work[i]=head[i];
        while(del=dfs(src,inf)) res+=del;
    }
    return res;
}

int n,m;
pii ps[maxm];
int ind[maxn],oud[maxn];

bool check(int mid)
{
    int ex=0;
    mem(ind,0);
    mem(oud,0);
    init(n+2,0,n+1);
    for(int i=0;i<m;i++)
    {
        pii x=ps[i];
        oud[x.ff]++;
        ind[x.ss]++;
        add_edge(x.ff,x.ss,1);
    }
    for(int i=1;i<=n;i++)
    {
        if(oud[i]>mid)
        {
            add_edge(0,i,oud[i]-mid);
            ex+=oud[i]-mid;
        }
        if(oud[i]<mid)
        {
            add_edge(i,n+1,mid-oud[i]);
        }
    }
    int f=fast_dinic();
    //printf("%d\n",f);
    return ex==f;
}

void printpath()
{
    for(int i=1;i<=n;i++)
    {
        for(int e=head[i];e!=-1;e=nxt[e])
        {
            if(e&1) continue;
            int v=ver[e];
            if(v<1||v>n||v<i) continue;
            if(flow[e])
            {
                printf("%d %d\n",i,v);
            }
            else
            {
                printf("%d %d\n",v,i);
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
    n=in(),m=in();
    for(int i=0;i<m;i++)
    {
        int a=in(),b=in();
        if(a>b) swap(a,b);
        ps[i]={a,b};
    }
    int lo=-1,hi=n,mid;
    while(hi-lo>1)
    {
        mid=(lo+hi)>>1;
        //printf("%d %d %d\n",lo,hi,mid);
        if(check(mid))
            hi=mid;
        else lo=mid;
    }
    if(check(lo))
    {
        cout<<lo<<endl;
    }
    else
    {
        check(hi);
        cout<<hi<<endl;
    }
    printpath();
    return 0;
}

