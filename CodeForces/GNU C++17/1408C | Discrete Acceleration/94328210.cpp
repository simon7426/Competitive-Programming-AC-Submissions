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
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
 
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
int a[100010],b[100010],n;
double l;
bool solve(double lim)
{
    int sp1=1;
    double y;
    double t1=lim;
    double dis1=0;
    for(int i=0;i<n;i++)
    {
        y = ((double)a[i]-dis1)/sp1;
        if(y<=t1)
        {
            dis1=(double)a[i];
            sp1++;
            t1-=y;
        }
        else
        {
            dis1+=t1*(double)sp1;
            t1=0;
            break;
        }
    }
    if(t1!=0)
    {
        dis1+=t1*(double)sp1;
    }
    int sp2=1;
    double t2=lim;
    double dis2=0;
    for(int i=0;i<n;i++)
    {
        y = ((double)b[i]-dis2)/sp2;
        if(y<=t2)
        {
            dis2=(double)b[i];
            sp2++;
            t2-=y;
        }
        else
        {
            dis2+=t2*(double)sp2;
            t2=0;
            break;
        }
    }
    if(t2!=0)
    {
        dis2+=t2*(double)sp2;
    }
    //cout<<dis1<<" "<<dis2<< " "<<dis1+dis2<<endl;
    if(dis1+dis2<l)
        return true;
    else
        return false;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tc=in();
    while(tc--)
    {
        n=in(),l=ind();
        for(int i=0;i<n;i++)
        {
            a[i]=in();
            b[i]=l-a[i];
        }
        reverse(b,b+n);
        double lo=0,hi=l,mid;
        while(fabs(hi-lo)>1e-7)
        {
            mid=(lo+hi)/2;
            //cout<<lo<< " "<<hi<<" "<<mid<<endl;
            //cout<<fabs(hi-lo)<<endl;
            if(solve(mid))
                lo=mid;
            else
                hi=mid;
 
        }
        printf("%.8f\n",mid);
    }
}