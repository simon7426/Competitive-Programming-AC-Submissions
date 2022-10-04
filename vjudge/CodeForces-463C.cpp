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
ll dp[2005][2005][5],a[2005][2005];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    int n,i,t,j;
    cin>>n;
    mem(dp,0);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp[i][j][0]=a[i][j]+dp[i-1][j-1][0];
            dp[i][j][1]=a[i][j]+dp[i-1][j+1][1];
        }
    }
    for(i=n;i>0;i--)
    {
        for(j=1;j<=n;j++)
        {
            dp[i][j][2]=a[i][j]+dp[i+1][j-1][2];
            dp[i][j][3]=a[i][j]+dp[i+1][j+1][3];
        }
    }
    //printf("\n");
    ll x,ans1=0L,ans2=0L;
    int k,y,x1=1,y1=1,x2=2,y2=1;
    for(i=1;i<=n;i++)
    {
        y^=1;
        for(j=1;j<=n;j++)
        {
            x=0L;
            for(int k=0;k<4;k++)
                x+=dp[i][j][k];
           dp[i][j][4]=x-3*a[i][j];
        }
        //printf("\n");
        //cout<<dp[i][j][4]<<endl;
        //cout<<y<<" "<<ans1<<" "<<ans2<<" "<<dp[i][j][4]<<endl;
        for(j=y+1;j<=n;j+=2)
        {
            if(dp[i][j][4]>ans1)
            {
                ans1=dp[i][j][4];
                x1=i;
                y1=j;
            }
        }
        for(j=y;j<=n;j+=2)
        {
            if(dp[i][j][4]>ans2)
            {
                ans2=dp[i][j][4];
                x2=i;
                y2=j;
            }
        }
    }
    cout<<ans1+ans2<<endl;
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}

