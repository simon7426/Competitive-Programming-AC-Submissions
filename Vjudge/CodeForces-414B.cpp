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
int dp[2005][2005];
vi v[2005];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int i,j,k;
    for(i=1;i<2005;i++)
    {
        for(j=i;j<2005;j+=i)
            v[j].pb(i);
    }
    mem(dp,0);
    for(i=1;i<2005;i++) dp[i][1]=1,dp[1][i]=1;
    int n=in(),m=in(),x;
    for(i=2;i<=m;i++)
    {
        for(j=2;j<=n;j++)
        {
            for(k=0;k<v[j].size();k++)
            {
                x=v[j][k];
                dp[j][i]=((dp[x][i-1]%MOD)+(dp[j][i]%MOD))%MOD;
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }*/
    int ans=0;
    for(i=1;i<=n;i++)
        ans=(ans+dp[i][m])%MOD;
    printf("%d\n",ans);
    return 0;
}

