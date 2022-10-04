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
 
ll a[100010],b[100010];
int bit1[100010],bit2[100010],ans[100010],pre[100010],uq;
int f(int x,int y)
{
    return (ans[x]<ans[y])?y:x;
}
void update1(int x,int y)
{
    for(;x<=uq;x+=(x&-x)) bit1[x]=f(bit1[x],y);
}
 
void update2(int x,int y)
{
    for(;x<=uq;x+=(x&-x)) bit2[x]=f(bit2[x],y);
}
 
int ans1(int x)
{
    int ans=0;
    for(;x;x-=(x&-x)) ans=f(ans,bit1[x]);
    return ans;
}
int ans2(int x)
{
    int ans=0;
    for(;x;x-=(x&-x)) ans=f(ans,bit2[x]);
    return ans;
}
stack<int> st;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in();
    ll d=inl();
    for(int i=1;i<=n;i++)
    {
        a[i]=inl();
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    uq = unique(b+1,b+n+1)-(b+1);
    //printf("%d\n",uq);
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(b+1,b+uq+1,a[i]+d)-b;
        int y=upper_bound(b+1,b+uq+1,a[i]-d)-(b+1);
        //printf("%lld %lld %d %d\n",a[i]+d,a[i]-d,x,y);
        int cal=f(ans1(y),ans2(uq-x+1));
        ans[i]=ans[cal]+1;
        pre[i]=cal;
        int cur = lower_bound(b+1,b+uq+1,a[i])-b;
        update1(cur,i);
        update2(uq-cur+1,i);
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=f(res,i);
    }
    printf("%d\n",ans[res]);
    while(res)
    {
        st.push(res);
        res=pre[res];
    }
    while(!st.empty())
    {
        printf("%d ",st.top());
        st.pop();
    }
    printf("\n");
}
 