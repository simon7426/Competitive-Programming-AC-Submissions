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
const int maxn=100010,maxm=10000010;
int n,m,tot,now,rt[maxn],lc[maxm],rc[maxm];
ll sum[maxm],add[maxm];
char op[5];
void pushup(int x)
{
    sum[x]=sum[lc[x]]+sum[rc[x]];
}
void build(int l,int r,int &rt)
{
    rt=++tot;
    if(l==r)
    {
        sum[rt]=in();
        return;
    }
    int m=(l+r)>>1;
    build(l,m,lc[rt]);
    build(m+1,r,rc[rt]);
    pushup(rt);
    //printf("%lld %d %d\n",sum[rt],l,r);
}
void update(int l,int r,int llim,int rlim,int val,int &rt)
{
    ++tot;
    lc[tot]=lc[rt];
    rc[tot]=rc[rt];
    add[tot]=add[rt];
    sum[tot]=sum[rt];
    rt=tot;
    if(llim<=l && r<=rlim)
    {
        add[rt]+=val;
        return;
    }
    sum[rt]+=(ll)val*(min(rlim,r)-max(llim,l)+1);
    int m=(l+r)>>1;
    if(llim<=m)
    {
        update(l,m,llim,rlim,val,lc[rt]);
    }
    if(m<rlim)
    {
        update(m+1,r,llim,rlim,val,rc[rt]);
    }
}
ll query(int l,int r,int llim,int rlim,int rt)
{
    //printf("%d %d %d %d %d\n",l,r,llim,rlim,rt);
    ll res=(ll) add[rt]*(min(rlim,r)-max(llim,l)+1);
    if(llim<=l && r<=rlim)
    {
        return sum[rt]+res;
    }
    int m=(l+r)>>1;
    if(llim<=m) res+=query(l,m,llim,rlim,lc[rt]);
    if(m<rlim) res+=query(m+1,r,llim,rlim,rc[rt]);
    return res;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int x,y,d;
    n=in(),m=in();
    build(1,n,rt[0]);
    while(m--)
    {
        scanf("%s",op);
        if(op[0]=='C')
        {
            x=in(),y=in(),d=in();
            rt[now+1]=rt[now];
            now++;
            update(1,n,x,y,d,rt[now]);
        }
        else if(op[0]=='H')
        {
            x=in(),y=in(),d=in();
            printf("%lld\n",query(1,n,x,y,rt[d]));
        }
        else if(op[0]=='Q')
        {
            x=in(),y=in();
            printf("%lld\n",query(1,n,x,y,rt[now]));
        }
        else
        {
            now=in();
            tot=rt[now+1]-1;
        }
    }
    return 0;
}

