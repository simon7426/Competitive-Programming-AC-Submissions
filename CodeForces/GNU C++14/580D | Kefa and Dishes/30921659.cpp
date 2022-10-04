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
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
 
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
ll dp[19][1<<18];
int a[19][19],n,m,k;
int val[18];
ll ans=0LL;
ll solve(int y,int bit,int cnt)
{
    if(cnt==m)
    {
        return 0;
    }
    ll &z=dp[y][bit];
    if(z!=-1)
        return z;
    z=0;
    for(int i=0;i<n;i++)
    {
        if(bit&(1<<i))
            continue;
        z=max(z,solve(i,bit|(1<<i),cnt+1)+val[i]+a[y][i]);
    }
    return z;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
        mem(dp,-1);
        mem(a,0);
        n=in(),m=in(),k=in();
        int i,t,u,v;
        for(i=0;i<n;i++)
            val[i]=in();
        for(i=0;i<k;i++)
        {
            u=in(),v=in(),t=in();
            --u,--v;
            a[u][v]=t;
        }
        printf("%I64d\n",solve(n,0,0));
}
 