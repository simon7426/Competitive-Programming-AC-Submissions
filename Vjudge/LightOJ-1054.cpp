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

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

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
int pri[1000010];
vi prime;
vll pfact;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int i,j,k=1;
    memset(pri,0,sizeof pri);
    for(i=2;i*i<=1000000;i+=k)
    {
        //cout<<pri[i]<<endl;
        if(pri[i]==0)
        {
            for(j=i*i;j<=1000000;j+=i)
            {
                pri[j]=1;
            }
        }
        if(i==3)
            k=2;
    }
    for(i=2;i<=1000000;i++)
    {
        if(pri[i]==0)
            prime.push_back(i);
    }
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        pfact.clear();
        int n=in(),m=in();
        for(i=0;i<prime.size()&&prime[i]*prime[i]<=n;i++)
        {
            k=0;
            while(n%prime[i]==0)
            {
                //cout<<n<<endl;
                k++;
                n/=prime[i];
            }
            //cout<<prime[i]<<" "<<k<<endl;
            if(k!=0)
            {
                //cout<<prime[i]<<" "<<k<<endl;
                pfact.pb(mp((ll)prime[i],(ll)k));
            }
        }
        if(n!=1)
        {
            pfact.pb(mp((ll)n,(ll)1));
        }
        /*for(i=0;i<pfact.size();i++)
            printf("%lld %lld\n",pfact[i].ff,pfact[i].ss);*/

        ll ans=1;
        for(i=0;i<pfact.size();i++)
        {
            ll a=pfact[i].ff;
            ll b=pfact[i].ss*(ll)m;
            ll c=modDiv(modPow(a,b+1)-1,a-(ll)1);
            //cout<<a<<" "<<b<<" "<<c<<endl;
            ans=modMul(ans,c);
        }
        printf("Case %d: %lld\n",tc,ans);
    }
}

