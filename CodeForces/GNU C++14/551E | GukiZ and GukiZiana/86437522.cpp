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
const int inf = 1000000000;
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
struct ds
{
    int v,pos;
    bool operator < (const ds &r) const
    {
        if(v==r.v) return pos<r.pos;
        return v<r.v;
    }
}a[500010];
struct block
{
    int l,r,val;
}b[1010];
int n,m,bnum,len;
 
int getfirst(int l,int r,int v)
{
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[mid].v<v) l=mid+1;
        else r=mid;
    }
    if(a[l].v!=v) return -1;
    return a[l].pos;
}
int getlast(int l,int r,int v)
{
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(a[mid].v>v) r=mid-1;
        else l=mid;
    }
    if(a[l].v!=v) return -1;
    return a[l].pos;
}
int getquery(int v)
{
    int lans=-1,rans=-1;
    for(int i=0;i<bnum;i++)
    {
        lans=getfirst(b[i].l,b[i].r-1,v-b[i].val);
        if(lans!=-1) break;
    }
    if(lans==-1) return -1;
    for(int i=bnum-1;i>=0;i--)
    {
        rans=getlast(b[i].l,b[i].r-1,v-b[i].val);
        if(rans!=-1) break;
    }
    return rans-lans;
}
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in();
    for(int i=0;i<n;i++)
    {
        a[i].v=in();
        a[i].pos=i;
    }
    len=sqrt(n);
    bnum=n/len;
    for(int i=0;i<bnum;i++)
    {
        b[i].l=i*len;
        b[i].r=b[i].l+len;
    }
    if(n%len)
    {
        b[bnum].l=bnum*len;
        b[bnum].r=n;
        ++bnum;
    }
    for(int i=0;i<bnum;i++)
    {
        b[i].val=0;
        sort(a+b[i].l,a+b[i].r);
    }
    int tp,x,y,z,llim,rlim,lcom,rcom;
    while(m--)
    {
        tp=in(),x=in();
        if(tp==1)
        {
            y=in(),z=in();
            --x,--y;
            llim=x/len;
            rlim=y/len;
            lcom=llim;
            rcom=rlim;
            if(x%len)
            {
                lcom=llim+1;
            }
            if(y%len<len-1)
            {
                rcom=rlim-1;
            }
            for(int i=lcom;i<=rcom;i++)
            {
                if(b[i].val<=inf)
                {
                    b[i].val+=z;
                }
            }
            if(llim<lcom)
            {
                for(int i=b[llim].l;i<b[llim].r;i++)
                {
                    if(a[i].v<=inf)
                    {
                        a[i].v+=b[llim].val;
                        if(a[i].pos>=x && a[i].pos<=y) a[i].v+=z;
                    }
                }
                b[llim].val=0;
                sort(a+b[llim].l,a+b[llim].r);
            }
            if(rcom<rlim)
            {
                for(int i=b[rlim].l;i<b[rlim].r;i++)
                {
                    if(a[i].v<=inf)
                    {
                        a[i].v+=b[rlim].val;
                        if(a[i].pos>=x && a[i].pos<=y) a[i].v+=z;
                    }
                }
                b[rlim].val=0;
                sort(a+b[rlim].l,a+b[rlim].r);
            }
        }
        else
        {
            printf("%d\n",getquery(x));
        }
    }
}
 