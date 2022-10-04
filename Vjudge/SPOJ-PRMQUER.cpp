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
#define Si 400100
//Segment tree
#define left(x) x<<1
#define right(x) (x<<1)+1
int st[Si],a[Si],lazy[Si];
int n;
const int lim=10000000;
bool sieve[10000010];
void build(int p,int l,int r)
{
    if(l==r)
        {
            if(a[l]<=lim) st[p]=(int)sieve[a[l]];
            else st[p]=0;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        int p1=st[left(p)],p2=st[right(p)];
        st[p]=p1+p2;
        //printf("%d %d %d %d\n",p,l,r,st[p]);
    }
}
void update(int p,int l,int r,int i,int j,int v)
{
    if(lazy[p]!=-1)
    {
        if(lazy[p]<=lim)
        {
            if(sieve[lazy[p]])
                st[p]=r-l+1;
            else
                st[p]=0;
        }
        else
            st[p]=0;
        if(l!=r)
        {
            lazy[left(p)]=lazy[p];
            lazy[right(p)]=lazy[p];
        }
        else
            a[l]=lazy[p];
        lazy[p]=-1;
    }
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i) return;
    if(l>=i&&r<=j)
    {
        if(v<=lim)
        {
            if(sieve[v])
                st[p]=r-l+1;
            else
                st[p]=0;
        }
        else
            st[p]=0;
        if(l!=r)
        {
            lazy[left(p)]=v;
            lazy[right(p)]=v;
        }
        else
            a[l]=v;
        return;
    }
    //printf("%d %d\n",st[p],v);
    update(left(p),l,(l+r)/2,i,j,v);
    update(right(p),1+(l+r)/2,r,i,j,v);
    int p1=st[left(p)],p2=st[right(p)];
    st[p]=p1+p2;
}
void updatesin(int p,int l,int r,int i,int j,int v)
{
    if(lazy[p]!=-1)
    {
        if(lazy[p]<=lim)
        {
            if(sieve[lazy[p]])
                st[p]=r-l+1;
            else
                st[p]=0;
        }
        else
            st[p]=0;
        if(l!=r)
        {
            lazy[left(p)]=lazy[p];
            lazy[right(p)]=lazy[p];
        }
        else
            a[l]=lazy[p];
        lazy[p]=-1;
    }
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i){return;}
    if(l>=i&&r<=j)
    {
        a[l]+=v;
        if(a[l]<=lim)
            st[p]=(int)sieve[a[l]];
        else
            st[p]=0;
        return;
    }
    //printf("%d %d\n",st[p],v);
    updatesin(left(p),l,(l+r)/2,i,j,v);
    updatesin(right(p),1+(l+r)/2,r,i,j,v);
    int p1=st[left(p)],p2=st[right(p)];
    st[p]=p1+p2;
}

void updatesin(int i,int v)
{
    updatesin(1,0,n-1,i,i,v);
}

void update(int i,int j,int v)
{
    update(1,0,n-1,i,j,v);
}
int rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(lazy[p]!=-1)
    {
        if(lazy[p]<=lim)
        {
            if(sieve[lazy[p]])
                st[p]=r-l+1;
            else
                st[p]=0;
        }
        else
            st[p]=0;
        if(l!=r)
        {
            lazy[left(p)]=lazy[p];
            lazy[right(p)]=lazy[p];
        }
        else
            a[l]=lazy[p];
        lazy[p]=-1;
    }
    if(l>=i&&r<=j) return st[p];
    int p1=rmq(left(p),l,(l+r)/2,i,j);
    int p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return p1+p2;
}
int rmq(int i,int j)
{
    return rmq(1,0,n-1,i,j);
}
void SegmentTree()
{
    memset(st,0,sizeof st);
    build(1,0,n-1);
}

main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,t,i,j,k,l,r,q,v;
    memset(sieve,true,sizeof sieve);
    k=1;t=sqrt(10000010)+100;
    for(i=2;i<=t;i+=k)
    {
        if(sieve[i]==true)
        {
            for(j=i*i;j<10000010;j+=i)
                sieve[j]=false;
        }
        if(i==3)k=2;
    }
    sieve[1]=false;
        memset(a,0,sizeof a);
        memset(st,0,sizeof st);
        memset(lazy,-1,sizeof lazy);
        n=in();
        int m=in();
        for(i=0;i<n;i++)
            a[i]=in();
        SegmentTree();
        char c[5];
        for(i=0;i<m;i++)
        {
            scanf("%s",c);
            if(c[0]=='R')
            {
                v=in();l=in();r=in();
                --l,--r;
                update(l,r,v);
            }
            else if(c[0]=='Q')
            {
                l=in();
                r=in();
                --l,--r;
                printf("%d\n",rmq(l,r));
            }
            else
            {
                v=in();
                l=in();
                --l;
                updatesin(l,v);
            }
        }
    return 0;
}
