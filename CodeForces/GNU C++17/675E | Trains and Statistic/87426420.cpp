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
int a[100010];
struct segmenttree
{
    int n;
    int st[mx];
    build()
    {
        //mem(st,0);
        build(1,1,n);
    }
    int fun(int l,int r)
    {
        if(a[l]>a[r])
            return l;
        return r;
    }
    void build(int p,int l,int r)
    {
        if(l==r)
            {
            st[p]=l;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
            }
        else
        {
            build(left(p),l,(l+r)/2);
            build(right(p),(l+r)/2+1,r);
            int p1=st[left(p)],p2=st[right(p)];
            st[p]=fun(p1,p2);
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    }
 
    int query(int p,int l,int r,int i,int j)
    {
        if(i>r||j<l)
            return -1;
        if(l>=i&&r<=j) return st[p];
        int p1=query(left(p),l,(l+r)/2,i,j);
        int p2=query(right(p),(l+r)/2+1,r,i,j);
        if(p1==-1) return p2;
        if(p2==-1) return p1;
        return fun(p1,p2);
    }
    int query(int i,int j)
    {
        return query(1,1,n,i,j);
    }
};
 
segmenttree seg;
ll dp[100010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in();
    seg.n=n;
    for(int i=1;i<=n-1;i++)
        a[i]=in();
    a[n]=n;
    dp[n]=0;
    seg.build();
    int q;
    ll ans=0;
    for(int i=n-1;i>0;i--)
    {
        q=seg.query(i+1,a[i]);
        //cout<<i+1<< " "<<a[i]<<" "<<q<<endl;
        dp[i]=dp[q]-(a[i]-q)+n-i;
        ans+=dp[i];
    }
    printf("%I64d\n",ans);
}
 