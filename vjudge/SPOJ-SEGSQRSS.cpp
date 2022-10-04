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
int st[Si],sta[Si],a[Si];
pii lazy[Si];
int n;
void build(int p,int l,int r)
{
    if(l==r)
        {
            st[p]=a[l]*a[l];
            sta[p]=a[l];
        }
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        int p1=st[left(p)],p2=st[right(p)];
        st[p]=p1+p2;
        int p3=sta[left(p)],p4=sta[right(p)];
        sta[p]=p3+p4;
    }
}
void update(int p,int l,int r,int i,int j,int v,int t)
{
    if(lazy[p].ff!=0)
    {
        int x=lazy[p].ff;
        if(lazy[p].ss==1)
        {
            st[p]=(r-l+1)*x*x;
            sta[p]=(r-l+1)*x;
        }
        else if(lazy[p].ss==2)
        {
            st[p]+=(r-l+1)*x*x+2*x*sta[p];
            sta[p]+=(r-l+1)*x;
        }
        if(l!=r)
        {
            if(lazy[p].ss==1)
            {
                lazy[left(p)].ff=lazy[p].ff;
                lazy[right(p)].ff=lazy[p].ff;
                lazy[left(p)].ss=lazy[p].ss;
                lazy[right(p)].ss=lazy[p].ss;
            }
            if(lazy[p].ss==2)
            {
                lazy[left(p)].ff+=lazy[p].ff;
                lazy[right(p)].ff+=lazy[p].ff;
                if(lazy[left(p)].ss==0)
                    lazy[left(p)].ss=2;
                if(lazy[right(p)].ss==0)
                    lazy[right(p)].ss=2;
            }
        }
        lazy[p].ff=0;
        lazy[p].ss=0;
    }
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i) return;
    if(l>=i&&r<=j)
    {
        if(t==1)
        {
            st[p]=(r-l+1)*v*v;
            sta[p]=(r-l+1)*v;
        }
        else if(t==2)
        {
            st[p]+=(r-l+1)*v*v+2*v*sta[p];
            sta[p]+=(r-l+1)*v;
        }
        if(l!=r)
        {
            if(t==1)
            {
                lazy[left(p)].ff=v;
                lazy[right(p)].ff=v;
                lazy[left(p)].ss=1;
                lazy[right(p)].ss=1;
            }
            else if(t==2)
            {
                lazy[left(p)].ff+=v;
                lazy[right(p)].ff+=v;
                if(lazy[left(p)].ss==0)
                    lazy[left(p)].ss=2;
                if(lazy[right(p)].ss==0)
                    lazy[right(p)].ss=2;
            }
        }
        return;
    }
    //printf("%d %d\n",st[p],v);
    update(left(p),l,(l+r)/2,i,j,v,t);
    update(right(p),1+(l+r)/2,r,i,j,v,t);
    int p1=st[left(p)],p2=st[right(p)];
    st[p]=p1+p2;
}
void update(int i,int j,int v,int t)
{
    update(1,0,n-1,i,j,v,t);
}
int rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(lazy[p].ff!=0)
    {
        int x=lazy[p].ff;
        if(lazy[p].ss==1)
        {
            st[p]=(r-l+1)*x*x;
            sta[p]=(r-l+1)*x;
        }
        else if(lazy[p].ss==2)
        {
            st[p]+=(r-l+1)*x*x+2*x*sta[p];
            sta[p]+=(r-l+1)*x;
        }
        if(l!=r)
        {
            if(lazy[p].ss==1)
            {
                lazy[left(p)].ff=lazy[p].ff;
                lazy[right(p)].ff=lazy[p].ff;
                lazy[left(p)].ss=lazy[p].ss;
                lazy[right(p)].ss=lazy[p].ss;
            }
            if(lazy[p].ss==2)
            {
                lazy[left(p)].ff+=lazy[p].ff;
                lazy[right(p)].ff+=lazy[p].ff;
                if(lazy[left(p)].ss==0)
                    lazy[left(p)].ss=2;
                if(lazy[right(p)].ss==0)
                    lazy[right(p)].ss=2;
            }
        }
        lazy[p].ff=0;
        lazy[p].ss=0;
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
    int tc,t,i,j,k,l,r,q,x;
    char c;
    char s[Si];
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        memset(a,0,sizeof a);
        memset(st,0,sizeof st);
        memset(sta,0,sizeof sta);
        memset(lazy,0,sizeof lazy);
        int m;
        n=in();
        m=in();
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        SegmentTree();
        printf("Case %d:\n",t);
        for(i=0;i<m;i++)
        {
            q=in();
            if(q==1)
            {
                l=in();r=in();x=in();
                --l,--r;
                update(l,r,x,2);
            }
            else if(q==2)
            {
                l=in();r=in();
                --l,--r;
                printf("%d\n",rmq(l,r));
            }
            else
            {
                l=in();r=in();x=in();
                --l,--r;
                update(l,r,x,1);
            }
        }
    }
    return 0;
}

