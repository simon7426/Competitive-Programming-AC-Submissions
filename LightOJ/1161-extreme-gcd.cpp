#include<bits/stdc++.h>
using namespace std;
//#define CP
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
ll dp[10010];
ll ans[10010];
ll nc(ll x)
{
    return (x*(x-1)*(x-2)*(x-3)/24);
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
        mem(dp,0);
        int n=in();
        for(int i=0;i<n;i++)
        {
            int x=in();
            for(int j=1;j*j<=x;j++)
            {
                if(x%j==0)
                {
                    dp[j]++;
                    if(j*j!=x) dp[x/j]++;
                }
            }
        }
        //for(int i=1;i<10;i++) printf("%d ",dp[i]);printf("\n");
        mem(ans,0);
        for(int i=10000;i>0;i--)
        {
            ans[i]=nc(dp[i]);
            for(int j=i+i;j<=10000;j+=i) ans[i]-=ans[j];
        }
        //for(int i=1;i<10;i++) printf("%lld ",nc(dp[i]));printf("\n");
        printf("Case %d: %lld\n",tc,ans[1]);
    }
}

