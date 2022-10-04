#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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
 
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
//inline ll modPow(ll b, ll p) { ll r = 1; while(p>0) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
//inline ll modInverse(ll a) { return modPow(a, MOD-2); }
//inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
 
int gcd(int a,int b) { return b==0 ? a:gcd(b,a%b);}
ll modPow(ll x,ll n)
{
    ll res=1;
    normal(x);
    if(x==0) return 0;
    while(n>0)
    {
        if(n&1)
            res=modMul(res,x);
        x=modMul(x,x);
        n>>=1;
    }
    return res;
}
//abcdefghijklmnopqrstuvwxyz//
vi sieve[100010];
int pre[100010];
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    for(int i=1;i<=100000;i++)
    {
        for(int j=1;i*j<=100000;j++)
        {
            sieve[i*j].pb(i);
        }
    }
    int n=in();
    for(int i=1;i<=n;i++)
        pre[in()]++;
    int mx,fl=0;
    for(int i=100000;i>=0;i--)
        {
            pre[i]+=pre[i+1];
            if(fl==0&&pre[i])
            {
                fl=1;
                mx=i;
            }
        }
    ll ans=0,tmp,tmp2,y,z;
    int x,sub;
    for(int i=1;i<=mx;i++)
    {
        tmp=1;
        sub=0;
        for(int j=sieve[i].size()-1;j>=0;j--)
        {
            x=sieve[i][j];
            if(x!=i)
            {
                y=modPow(j+1,pre[x]-sub);
                tmp=modMul(tmp,y);
            }
            else
            {
                y=modPow(j+1,pre[x]-sub);
                z=modPow(j,pre[x]-sub);
                tmp2=modSub(y,z);
                tmp=modMul(tmp,tmp2);
            }
            sub=pre[x];
        }
        ans=modAdd(tmp,ans);
    }
    printf("%I64d\n",ans);
}
 