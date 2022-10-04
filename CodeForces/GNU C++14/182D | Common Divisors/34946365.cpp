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
 
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
 
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
int h1[100010],h2[100010],po[100010],alp=26;
char s[100010],t[100010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    scanf("%s%s",s,t);
    int n=strlen(s),m=strlen(t);
    int i,j,k;
    po[0]=1;
    for(i=1;i<=max(n,m);i++) po[i]=modMul(po[i-1],alp);
    h1[0]=h2[0]=0;
    for(i=1;i<=n;i++) h1[i]=modAdd(h1[i-1],modMul(po[i],(ll)(s[i-1]-'a'+1)));
    for(i=1;i<=m;i++) h2[i]=modAdd(h2[i-1],modMul(po[i],(ll)(t[i-1]-'a'+1)));
   // for(i=1;i<=n;i++) cout<<h1[i]<<" ";cout<<endl;
   // for(i=1;i<=m;i++) cout<<h2[i]<<" ";cout<<endl;
    int x=gcd(n,m),y,z;
    int ans=0;
    for(i=1;i<=x;i++)
    {
        if(n%i==0&&m%i==0)
        {
            int f=0;
            k=h1[i];
            //cout<<i<<" "<<k<<endl;
            for(j=i;j<=n;j+=i)
            {
                y=h1[j]-h1[j-i];
                z=modDiv(y,po[j-i]);
                //cout<<n<<" "<<k<<" "<<y<<" "<<z<<endl;
                if(z!=k)
                {
                    f=1;
                    break;
                }
            }
            if(f==1) continue;
            for(j=i;j<=m;j+=i)
            {
                y=h2[j]-h2[j-i];
                z=modDiv(y,po[j-i]);
                //cout<<m<<" "<<k<<" "<<y<<" "<<z<<endl;
                if(z!=k)
                {
                    f=1;
                    break;
                }
            }
            if(f!=1) ans++;
        }
    }
    printf("%d\n",ans);
}
 