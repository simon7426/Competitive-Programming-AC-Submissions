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
#define MOD 998244353
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
const int base=131;
#define left(x) x<<1
#define right(x) (x<<1)+1
ll f[100010],sf[100010];
char s[100010];
void init()
{
    f[0]=1;
    sf[0]=1;
    for(int i=1;i<100010;i++)
    {
        f[i]=(f[i-1]*10)%MOD;
        sf[i]=(sf[i-1]+f[i])%MOD;
    }
}
 
struct segmenttree
{
    int n;
    ll st[mx];
    ll lazy[mx];
    build()
    {
        build(1,1,n);
    }
    void down(int p,int l,int r)
    {
        if(lazy[p]!=-1)
        {
            int mid=(l+r)/2;
            lazy[left(p)]=lazy[right(p)]=lazy[p];
            st[left(p)]=(sf[mid-l]*lazy[p])%MOD;
            st[right(p)]=(sf[r-mid-1]*lazy[p])%MOD;
            lazy[p]=-1;
        }
    }
    void build(int p,int l,int r)
    {
        lazy[p]=-1;
        if(l==r)
        {
            st[p]=s[l]-'0';
            return;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
        int mid=(l+r)/2;
        build(left(p),l,mid);
        build(right(p),mid+1,r);
        st[p]=(st[left(p)]+(st[right(p)]*f[mid-l+1]%MOD))%MOD;
        //printf("%d %d %d %d\n",p,l,r,st[p]);
    }
    void update(int p,int l,int r,int i,int j,int v)
    {
        if(i<=l&&r<=j)
        {
            st[p]=sf[r-l]*v%MOD;
            lazy[p]=v;
            return;
        }
        down(p,l,r);
        int mid=(l+r)/2;
        if(i<=mid)update(left(p),l,mid,i,j,v);
        if(j>mid)update(right(p),mid+1,r,i,j,v);
        st[p]=(st[left(p)]+(st[right(p)]*f[mid-l+1]%MOD))%MOD;
    }
 
    ll query(int p,int l,int r,int i,int j)
    {
        if(i>j) return 0;
        if(i<=l&&r<=j) return st[p];
        down(p,l,r);
        int mid=(l+r)/2;
        if(j<=mid) return query(left(p),l,(l+r)/2,i,j);
        else if(i>mid) return query(right(p),(l+r)/2+1,r,i,j);
        else
        {
            return (query(left(p),l,(l+r)/2,i,j)+(query(right(p),(l+r)/2+1,r,i,j)*f[mid-max(i,l)+1]%MOD))%MOD;
        }
    }
};
 
segmenttree seg;
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    init();
    int n=in(),m=in(),k=in(),i;
    scanf("%s",s+1);
    seg.n=n;
    seg.build();
    int l,r,v,d;
    m+=k;
    for(i=0;i<m;i++)
    {
        int t=in();
        if(t==1)
        {
            l=in(),r=in(),v=in();
            seg.update(1,1,n,l,r,v);
        }
        else
        {
            l=in(),r=in(),d=in();
            ll a=seg.query(1,1,n,l,r-d),b=seg.query(1,1,n,l+d,r);
            printf("%s\n",(a==b)?"YES":"NO");
        }
    }
}