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
vi g[100010];
int sta[100010],fin[100010], val[100010],vis[100010];
ll a[100010];
int k;
void dfs(int x)
{
    vis[x]=1;
    sta[x]=k;
    a[k]=(ll)val[x];
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(!vis[v])
        {
            k++;
            dfs(v);
        }
    }
    fin[x]=k;
}

////////////////////////////
//Segment tree
#define Si 400100
#define left(x) x<<1
#define right(x) (x<<1)+1
ll st[Si],stm[Si],lazy[Si];
int n;
void build(int p,int l,int r)
{
    if(l==r)
        {
            st[p]=(ll)a[l];
            stm[p]=(ll)a[l];
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        ll p1=st[left(p)],p2=st[right(p)];
        st[p]=p1+p2;
        ll p3=stm[left(p)],p4=stm[right(p)];
        stm[p]=min(p3,p4);
        //printf("%d %d %d %d\n",p,l,r,st[p]);
    }
}
void update(int p,int l,int r,int i,int j,ll v)
{
    if(lazy[p]!=0)
    {
        st[p]+=(ll)(r-l+1)*lazy[p];
        stm[p]+=lazy[p];
        if(l!=r)
        {
            lazy[left(p)]+=lazy[p];
            lazy[right(p)]+=lazy[p];
        }
        else a[l]+=lazy[p];
        lazy[p]=0;
    }
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i) return;
    if(l>=i&&r<=j)
    {
        st[p]+=(ll)(r-l+1)*v;
        stm[p]+=v;
        if(l!=r)
        {
            lazy[left(p)]+=v;
            lazy[right(p)]+=v;
        }
        else
            a[l]+=v;
        return;
    }
    //printf("%d %d\n",st[p],v);
    update(left(p),l,(l+r)/2,i,j,v);
    update(right(p),1+(l+r)/2,r,i,j,v);
    ll p1=st[left(p)],p2=st[right(p)];
    st[p]=p1+p2;
    ll p3=stm[left(p)],p4=stm[right(p)];
    stm[p]=min(p3,p4);
}
void update(int i,int j,ll v)
{
    update(1,0,n-1,i,j,v);
}
ll rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(lazy[p]!=0)
    {
        st[p]+=(r-l+1)*lazy[p];
        stm[p]+=lazy[p];
        if(l!=r)
        {
            lazy[left(p)]+=lazy[p];
            lazy[right(p)]+=lazy[p];
        }
        else a[l]+=lazy[p];
        lazy[p]=0;
    }
    if(l>=i&&r<=j) return st[p];
    ll p1=rmq(left(p),l,(l+r)/2,i,j);
    ll p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return p1+p2;
}
ll rmq(int i,int j)
{
    return rmq(1,0,n-1,i,j);
}

ll rmq2(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(lazy[p]!=0)
    {
        st[p]+=(r-l+1)*lazy[p];
        stm[p]+=lazy[p];
        if(l!=r)
        {
            lazy[left(p)]+=lazy[p];
            lazy[right(p)]+=lazy[p];
        }
        else a[l]+=lazy[p];
        lazy[p]=0;
    }
    if(l>=i&&r<=j) return stm[p];
    ll p1=rmq2(left(p),l,(l+r)/2,i,j);
    ll p2=rmq2(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return min(p1,p2);
}
ll rmq2(int i,int j)
{
    return rmq2(1,0,n-1,i,j);
}

void SegmentTree()
{
    memset(st,0,sizeof st);
    memset(stm,63,sizeof stm);
   // cout<<"here"<<endl;
    build(1,0,n-1);
}

////////////////////////////

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        int i;
        for(i=0;i<100010;i++) g[i].clear();
        mem(sta,0);
        mem(fin,0);
        mem(vis,0);
        mem(a,0);
        mem(lazy,0);
        k=0;
        int num=in();
        int m=in(),j,p,t,v;
        for(i=1;i<=num;i++)
        {
            p=in(),v=in();
            g[p].pb(i);
            val[i]=v;
        }
        dfs(1);
        /*for(i=1;i<=n;i++)
        {
            printf("%d %d %d %d\n",sta[i],fin[i],val[i],a[sta[i]]);
        }*/
        n=k+1;
        SegmentTree();
        printf("Case %d:\n",tc);
        for(i=0;i<m;i++)
        {
            t=in();p=in();
            if(t==1)
            {
                printf("%lld\n",rmq(sta[p],fin[p]));
            }
            else
            {
                v=rmq2(sta[p],fin[p]);
                update(sta[p],fin[p],(ll)min(v,1000));
            }
        }
    }
}

