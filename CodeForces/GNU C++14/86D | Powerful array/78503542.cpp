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
int a[200010], block[200010];
int cnt[1000010];
ll ans[200010];
int n,q;
ll res=0;
struct node
{
    int l,r,id;
    bool operator <(const node b)const
    {
        if(block[l]!=block[b.l])
            return l<b.l;
        if(block[l]&1) return r<b.r;
        else return r>b.r;
    }
}qs[200010];
 
void add(int x)
{
    cnt[x]++;
    res+=(((ll)cnt[x]*(ll)cnt[x])-((ll)((ll)cnt[x]-1LL)*(ll)((ll)cnt[x]-1LL)))*(ll)x;
}
void del(int x)
{
    cnt[x]--;
    res+=(((ll)cnt[x]*(ll)cnt[x])-((ll)((ll)cnt[x]+1LL)*(ll)((ll)cnt[x]+1LL)))*(ll)x;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),q=in();
    for(int i=1;i<=n;i++)a[i]=in();
    for(int i=1;i<=q;i++)
    {
        qs[i].l=in(),qs[i].r=in(),qs[i].id=i;
    }
    int sz=sqrt(n);
    for(int i=1;i<=n;i+=sz) block[i]=1;
    for(int i=2;i<=n;i++) block[i]+=block[i-1];
    sort(qs+1,qs+q+1);
    int lp=1,rp=0;
    for(int i=1;i<=q;i++)
    {
        while(rp<qs[i].r) add(a[++rp]);
        while(lp>qs[i].l) add(a[--lp]);
        while(rp>qs[i].r) del(a[rp--]);
        while(lp<qs[i].l) del(a[lp++]);
        ans[qs[i].id]=res;
    }
    for(int i=1;i<=q;i++)
        printf("%I64d\n",ans[i]);
}
 