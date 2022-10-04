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
pii st[Si];
pii a[Si];
int n;
const pii mx = {1e9+7,1e9+8};
void build(int p,int l,int r)
{
 
    //printf("%d %d %d\n",p,l,r);
    if(l==r)
        {
            st[p].ff=st[p].ss=a[l].ff;
            //printf("%d %d %d %d\n",p,l,r,st[p].ff);
        }
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
 
        pii p1=st[left(p)],p2=st[right(p)];
        st[p].ff=gcd(p1.ff,p2.ff);
        st[p].ss=min(p1.ss,p2.ss);
        //printf("%d %d %d %d\n",p,l,r,st[p]);
    }
}
/*
void update(int p,int l,int r,int i,int j,int v)
{
    if(lazy[p]!=-1)
    {
        st[p]=(r-l+1)*lazy[p];
        if(l!=r)
        {
            lazy[left(p)]=lazy[p];
            lazy[right(p)]=lazy[p];
        }
        lazy[p]=-1;
    }
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i) return;
    if(l>=i&&r<=j)
    {
        st[p]=(r-l+1)*v;
        if(l!=r)
        {
            lazy[left(p)]=v;
            lazy[right(p)]=v;
        }
        return;
    }
    //printf("%d %d\n",st[p],v);
    update(left(p),l,(l+r)/2,i,j,v);
    update(right(p),1+(l+r)/2,r,i,j,v);
    int p1=st[left(p)],p2=st[right(p)];
    st[p]=p1+p2;
}
 
void update(int i,int j,int v)
{
    update(1,0,n-1,i,j,v);
}
*/
pii rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return mx;
    if(l>=i&&r<=j) return st[p];
    pii p1=rmq(left(p),l,(l+r)/2,i,j);
    pii p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==mx) return p2;
    if(p2==mx) return p1;
    pii tmp = {gcd(p1.ff,p2.ff),min(p1.ss,p2.ss)};
    return tmp;
}
pii rmq(int i,int j)
{
    return rmq(1,0,n-1,i,j);
}
void SegmentTree()
{
    //memset(st,0,sizeof st);
    build(1,0,n-1);
}
 
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    n=in();
    for(int i=0;i<n;i++)
    {
        a[i].ff=in();
        a[i].ss=i+1;
    }
    SegmentTree();
    sort(a,a+n);
    int q=in();
    while(q--)
    {
        int l=in(),r=in();
        pii ans = rmq(l-1,r-1);
        if(ans.ff==ans.ss)
        {
            int res=upper_bound(a,a+n,mp(ans.ff,r))-lower_bound(a,a+n,mp(ans.ff,l));
            printf("%d\n",r-l+1-res);
        }
        else
            printf("%d\n",r-l+1);
    }
    return 0;
}
 