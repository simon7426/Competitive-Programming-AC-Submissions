#include<bits/stdc++.h>
using namespace std;
//#define CP
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
#define MOD 100000007
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
ll power( ll x, ll n)
{
    if(n==0)return 1;
    else if(n%2==0)
    {
        ll y=power(x,n/2);
        return (y*y)%MOD;
    }
    else
        return (x*power(x,n-1))%MOD;
}
//abcdefghijklmnopqrstuvwxyz//
ll fa[1000020],ifa[1000020],res;
int n,k,ra[12],dp[1<<12];
ll ncr(ll x,ll y)
{
    if(y>x) return 0;
    ll lol=(ifa[y]*ifa[x-y])%MOD;
    return (fa[x]*lol)%MOD;
}
void fun(ll cur)
{
    int cnt=__builtin_popcount(cur);
    if(cnt>n||dp[cur]==1) return;
    ll tmp=k;
    for(int i=0;i<n;i++)
    {
        if(cur&(1<<i))
        {
            tmp-=ra[i];
        }
    }
    if(tmp>=0)
    {
        if(cnt&1)
        {
            res-=ncr(tmp+n-1,n-1);
            res%=MOD;
            if(res<0)res+=MOD;
        }
        else
        {
            res+=ncr(tmp+n-1,n-1);
            res%=MOD;
        }
    }
    dp[cur]=1;
    for(int i=0;i<n;i++)
    {
        if((cur&(1<<i))==0)
        {
          fun(cur|(1<<i));
        }
    }
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    fa[0]=fa[1]=1;
    ifa[0]=ifa[1]=1;
    for(int i=2;i<1000020;i++)
    {
        fa[i]=(i*fa[i-1])%MOD;
        ifa[i]=(power(i,MOD-2)*ifa[i-1])%MOD;
        fa[i]%=MOD;
        ifa[i]%=MOD;
    }
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        n=in(),k=in();

        int x,y;
        for(int i=0;i<n;i++)
        {
            x=in();y=in();
            ra[i]=y-x+1;
            k-=x;
        }
        res=0;
        mem(dp,-1);
        fun(0);
        printf("Case %d: %lld\n",tc,res);
    }
}
