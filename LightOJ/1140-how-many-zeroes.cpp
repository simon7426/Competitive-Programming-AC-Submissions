//spoj sqamod
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
ll k,dp[12][2][2][12];
vi dig;
ll fun(int idx,int li,int f,int n)
{
    if(idx==-1)
    {
        if(f==0)
            {
                //printf("%d %d %d %d %d\n",idx,li,f,digsum,n);
                return n;
            }
        else return 0;
    }
    if(dp[idx][li][f][n]!=-1)
       return dp[idx][li][f][n];
    //printf("%d %d %d %d %d\n",idx,li,f,digsum,n);
    ll ans=0;
    int i;
    if(li==1)
    {
        for(i=0;i<dig[idx];i++)
        {
            if(f==1&&i==0)
              ans+=fun(idx-1,0,1,n);
            else if(f==0 && i==0)
                ans+=fun(idx-1,0,0,n+1);
            else
                ans+=fun(idx-1,0,0,n);
        }
        if(dig[idx]==0)ans+=fun(idx-1,1,0,n+1);
        else ans+=fun(idx-1,1,0,n);
    }
    else
    {
        for(i=0;i<=9;i++)
        {
            if(f==1&&i==0)
              ans+=fun(idx-1,0,1,n);
            else if((i==0) && (f==0))
                ans+=fun(idx-1,0,0,n+1);
            else
                ans+=fun(idx-1,0,0,n);
        }
    }
    return dp[idx][li][f][n]=ans;
}

ll calc(ll x)
{
    if(x<=0) return 0;
    //printf("%d",x);
    dig.clear();
    mem(dp,-1);
    while(x!=0)
    {
        dig.pb(x%10);
        x/=10;
    }
    /*for(int i=0;i<dig.size();i++)
    {
        printf("%d ",dig[i]);
    }
    printf("\n");*/
    ll ans = fun(dig.size()-1,1,1,0);
    //printf(" %d\n",ans);
    return ans;
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        ll a=inl(),b=inl();
        //cout<<a<<" "<<b<<endl;
        ll ans1=calc(a-1);
        ll ans2=calc(b);
        if(a==0)ans2++;
        //printf("%lld %lld\n",ans1,ans2);
        printf("Case %d: %lld\n",tc,ans2-ans1);
    }
}
