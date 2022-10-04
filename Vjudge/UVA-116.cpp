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
int dp[10][100],a[10][100],d[10][100];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int i,j,k,n,m,x;
    while(scanf("%d %d",&n,&m)==2)
    {
        mem(dp,0);
        mem(d,0);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++) a[i][j]=in();
        for(i=0;i<n;i++) dp[i][m-1]=a[i][m-1];
        for(j=m-2;j>=0;j--)
        {
            for(i=0;i<n;i++)
            {
                dp[i][j]=INT_MAX;
                for(k=-1;k<=1;k++)
                {
                   x=(i+k+n)%n;
                   //printf("%d ",x);
                   if(dp[x][j+1]+a[i][j]<dp[i][j]||(dp[x][j+1]+a[i][j]==dp[i][j]&&x<d[i][j]))
                    dp[i][j]=dp[x][j+1]+a[i][j],d[i][j]=x;
                }
            }
        }
        int ans=INT_MAX;
        for(i=0;i<n;i++)
        {
            if(dp[i][0]<ans)
            {
                ans=dp[i][0];
                x=i;
            }
        }
        printf("%d",x+1);
        for(i=0;i<m-1;i++)
        {
            x=d[x][i];
            printf(" %d",x+1);
        }
        printf("\n%d\n",ans);
    }
}
