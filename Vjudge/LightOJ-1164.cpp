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
const int mx=400010;
#define left(x) x<<1
#define right(x) (x<<1)+1
//int a[100010];
struct segmenttree
{
    int n;
    ll st[mx];
    ll lazy[mx];
    void reset()
    {
        mem(st,0);
        mem(lazy,0);
        //build(1,0,n-1);
    }
    /* void build(int p,int l,int r)
    {
        if(l==r)
            {
            st[p]=a[l];
            //printf("%d %d %d %d\n",p,l,r,st[p]);
            }
        else
        {
            build(left(p),l,(l+r)/2);
            build(right(p),(l+r)/2+1,r);
            ll p1=st[left(p)],p2=st[right(p)];
            st[p]=p1+p2;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    }*/
    void update(int p,int l,int r,int i,int j,int v)
    {
        if(lazy[p]!=0)
        {
            st[p]+=(r-l+1)*lazy[p];
            if(l!=r)
            {
                lazy[left(p)]+=lazy[p];
                lazy[right(p)]+=lazy[p];
            }
            lazy[p]=0;
        }
        //printf("%d %d %d %d\n",l,r,i,j);
        if(l>r||l>j||r<i) return;
        if(l>=i&&r<=j)
        {
            st[p]+=(r-l+1)*v;
            if(l!=r)
            {
                lazy[left(p)]+=v;
                lazy[right(p)]+=v;
            }
            return;
        }
        //printf("%d %d\n",st[p],v);
        update(left(p),l,(l+r)/2,i,j,v);
        update(right(p),1+(l+r)/2,r,i,j,v);
        ll p1=st[left(p)],p2=st[right(p)];
        st[p]=p1+p2;
    }

    void update(int i,int j,int v)
    {
        //printf("%d %d %d\n",i,j,v);
        update(1,0,n-1,i,j,v);
    }

    ll query(int p,int l,int r,int i,int j)
    {
        if(i>r||j<l)
            return -1;
        if(lazy[p]!=0)
        {
            st[p]+=(r-l+1)*lazy[p];
            if(l!=r)
            {
                lazy[left(p)]+=lazy[p];
                lazy[right(p)]+=lazy[p];
            }
            lazy[p]=0;
        }
        if(l>=i&&r<=j) return st[p];
        ll p1=query(left(p),l,(l+r)/2,i,j);
        ll p2=query(right(p),(l+r)/2+1,r,i,j);
        if(p1==-1) return p2;
        if(p2==-1) return p1;
        return p1+p2;
    }
    ll query(int i,int j)
    {
        return query(1,0,n-1,i,j);
    }
};

segmenttree seg;
int n,q;

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        n=in(),q=in();
        seg.n=n;
        seg.reset();
        printf("Case %d:\n",tc);
        for(int i=0;i<q;i++)
        {
            int w,x,y,z;
            w=in();
            if(w==0)
            {
                x=in(),y=in(),z=in();
                seg.update(x,y,z);
            }
            else
            {
                x=in(),y=in();
                ll ans=seg.query(x,y);
                printf("%lld\n",ans);
            }
            
        }


    }
}

