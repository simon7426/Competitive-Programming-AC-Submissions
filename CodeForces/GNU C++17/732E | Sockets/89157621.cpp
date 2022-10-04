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
struct node
{
    int val,pos;
    bool operator < (const node& ri) const
    {
        return val<ri.val;
    }
    bool operator == (const node& ri) const
    {
        return val==ri.val;
    }
}a[200010],b[200010];
int ans[200010],ban[200010],use[200010],cnt[200010],res,sum;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),m=in();
    for(int i=1;i<=n;i++)
    {
        a[i].val=in();
        a[i].pos=i;
    }
    int ma=0;
    for(int i=1;i<=m;i++)
    {
        b[i].val=in();
        b[i].pos=i;
        ma=max(ma,a[i].val);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int k=0;;k++)
    {
        for(int t1=1,t2=1;t1<=n;t1++)
        {
            if(!ban[t1])
            {
                for(;(b[t2]<a[t1] || use[t2])&& t2<=m;t2++);
                if(t2>m) break;
                if(b[t2]==a[t1])
                {
                    ban[t1]=1;
                    res++;
                    use[t2]=t1;
                    cnt[t2]=k;
                    sum+=k;
                    t2++;
                }
            }
        }
        bool fl=1;
        for(int i=1;i<=m;i++)
        {
            if(b[i].val!=1)
                fl=0;
        }
        if(fl) break;
        for(int i=1;i<=m;i++)
            b[i].val=(b[i].val+1)>>1;
    }
    printf("%d %d\n",res,sum);
    for(int i=1;i<=m;i++)
        ans[b[i].pos]=cnt[i];
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    printf("\n");
    mem(ans,0);
    for(int i=1;i<=m;i++)
    {
        if(use[i])
        {
            ans[a[use[i]].pos]=b[i].pos;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}
 