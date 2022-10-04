//lightoj 1348
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
    int x,y,nxt;
    edge(){}
    edge(int xx,int yy,int nxxt)
    {
        x=xx;
        y=yy;
        nxt=nxxt;
    }
}g[60010];
int cnt=0;
int head[30010];
void addedge(int x,int y)
{
    g[cnt]=edge(x,y,head[x]);
    head[x]=cnt++;
    g[cnt]=edge(y,x,head[y]);
    head[y]=cnt++;
}
int n,a[30010],idx;
int len[30010],pa[30010],si[30010],son[30010];
int top[30010],id[30010],id2[30010];
void dfs1(int x,int par,int le)
{
    len[x]=le,pa[x]=par,son[x]=0,si[x]=1;
    for(int i=head[x];i!=-1;i=g[i].nxt)
    {
        int y=g[i].y;
        if(y==par) continue;
        dfs1(y,x,le+1);
        si[x]+=si[y];
        if(si[son[x]]<si[y])son[x]=y;
    }
}
void dfs2(int x,int topp)
{
    top[x]=topp;id[x]=++idx;
    if(son[x])dfs2(son[x],topp);
    for(int i=head[x];i!=-1;i=g[i].nxt)
    {
        int y=g[i].y;
        if(y==pa[x]||y==son[x]) continue;
        dfs2(y,y);
    }
}
int lft[120012],rht[120012],sum[120012];
void build(int p,int l,int r)
{
    lft[p]=l,rht[p]=r;
    if(l==r)
    {
        sum[p]=a[id2[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    sum[p]=sum[2*p]+sum[2*p+1];
}
void modify(int p,int pos,int c)
{
    if(lft[p]==rht[p]&&lft[p]==pos)
    {
        sum[p]=c;return;
    }
    int mid=(lft[p]+rht[p])>>1;
    if(pos<=mid) modify(2*p,pos,c);
    else modify(2*p+1,pos,c);
    sum[p]=sum[2*p]+sum[2*p+1];
}
int query2(int p,int l,int r)
{
    if(l<=lft[p]&&rht[p]<=r) return sum[p];

    int ans=0;
    int mid=(lft[p]+rht[p])>>1;
    //cout<<p<<" "<<l<<" "<<r<<" "<<mid<<endl;
    if(l<=mid)ans+=query2(2*p,l,r);
    if(r>mid) ans+=query2(2*p+1,l,r);
    return ans;
}
int query1(int x,int y)
{
    int tp1=top[x],tp2=top[y];
    int ans=0;
    while(tp1!=tp2)
    {
        //cout<<tp1<<" "<<tp2<<" "<<len[tp1]<<" "<<len[tp2]<<endl;
        if(len[tp1]<len[tp2])
        {
            swap(tp1,tp2);
            swap(x,y);
        }
        ans+=query2(1,id[tp1],id[x]);
        x=pa[tp1];
        tp1=top[x];
    }
    if(len[x]>len[y]) swap(x,y);
    ans+=query2(1,id[x],id[y]);
    return ans;
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
        mem(head,-1);
        cnt=0;
        n=in();
        for(int i=1;i<=n;i++)
            a[i]=in();
        int x,y;
        for(int i=0;i<n-1;i++)
        {
            x=in(),y=in();
            addedge(x+1,y+1);
        }
        idx=0;
        dfs1(1,0,1);
        dfs2(1,1);
        for(int i=1;i<=n;i++)
            id2[id[i]]=i;
        build(1,1,idx);
       // for(int i=1;i<=n;i++) printf("%d ",id[i]);printf("\n");
        printf("Case %d:\n",tc);
        int q=in(),t;
        for(int i=0;i<q;i++)
        {
            t=in(),x=in(),y=in();
            if(t) modify(1,id[x+1],y);
            else printf("%d\n",query1(x+1,y+1));
        }
    }
}


