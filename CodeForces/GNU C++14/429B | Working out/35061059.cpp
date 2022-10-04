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
const int mx=1010;
int dp1[mx][mx],dp2[mx][mx],dp3[mx][mx],dp4[mx][mx];
int a[mx][mx];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),m=in();
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            a[i][j]=in();
    }
    mem(dp1,0),mem(dp2,0),mem(dp3,0),mem(dp4,0);
    for(i=1;i<=n;i++) dp1[i][1]=dp1[i-1][1]+a[i][1];
    for(i=1;i<=m;i++) dp1[1][i]=dp1[1][i-1]+a[1][i];
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
    }
    for(i=n;i>0;i--) dp2[i][m]=dp2[i+1][m]+a[i][m];
    for(i=m;i>0;i--) dp2[n][i]=dp2[n][i+1]+a[n][i];
    for(i=n-1;i>0;i--)
    {
        for(j=m-1;j>0;j--)
            dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+a[i][j];
    }
    for(i=n;i>0;i--) dp3[i][1]=dp3[i+1][1]+a[i][1];
    for(i=1;i<=m;i++) dp3[n][i]=dp3[n][i-1]+a[n][i];
    for(i=n-1;i>0;i--)
    {
        for(j=2;j<=m;j++)
            dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+a[i][j];
    }
    for(i=1;i<=n;i++) dp4[i][m]=dp4[i-1][m]+a[i][m];
    for(i=m;i>0;i--) dp4[1][i]=dp4[1][i+1]+a[1][i];
    for(i=2;i<=n;i++)
    {
        for(j=m-1;j>0;j--)
            dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+a[i][j];
    }
    /*printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d ",dp1[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d ",dp2[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d ",dp3[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d ",dp4[i][j]);
        printf("\n");
    }
    printf("\n");*/
    int ans=0,t;
    for(i=2;i<=n-1;i++)
    {
        for(j=2;j<=m-1;j++)
        {
            t=max(dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j],dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);
            ans=max(ans,t);
        }
    }
    printf("%d\n",ans);
}
 