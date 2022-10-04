#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, int> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
//#define mp make_pair
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
map<pll,pll> mp;
pll fun(ll x,int y)
{
    //printf("%lld %d\n",x,y);
    if(x==0) return {0,0};
    if(x<10)
    {
        pll ret={1,0};
        if(x<y) ret.ss=x-y;
        return ret;
    }
    pll cs={x,y};
    if(mp.count(cs)) return mp[cs];
    ll lim=1;
    while(lim<=x/10) lim*=10;
    pll ret={0,0};
    while(1)
    {
        //printf("%lld\n",x);
        int tmp=y;
        int fdig=x/lim;
        if(fdig>tmp) tmp=fdig;
        pll cnt=fun(x%lim,tmp);
        ret.ff+=cnt.ff;
        x-=x%lim;
        if(cnt.ss<0) x+=cnt.ss;
        else if(cnt.ss==0)
        {
            x-=tmp;
            if(tmp>0)ret.ff++;
        }
        if(fdig==0) break;
    }
    ret.ss=x;
    return mp[cs]=ret;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    ll n=inl();
    ll ans=fun(n,0).ff;
    printf("%I64d\n",ans);
}
 