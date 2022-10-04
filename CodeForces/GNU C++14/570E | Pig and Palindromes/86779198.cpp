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
ll dp[2][505][505];
char s[505][505];
int dxl[]={-1,0},dyl[]={0,-1},dxr[]={1,0},dyr[]={0,1};
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),m=in();
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    if(s[0][0]!=s[n-1][m-1])
    {
        printf("0\n");
        return 0;
    }
    dp[0][0][n-1]=1;
    int tot=(n+m-2)>>1,cur=0;
    int ly,ry,txl,tyl,txr,tyr;
    for(int k=1;k<=tot;k++,cur^=1)
    {
        mem(dp[cur^1],0);
        for(int i=0;i<=min(k,n-1);i++)
        {
            for(int j=max(0,n-1-k);j<=n-1;j++)
            {
                ly=k-i;
                ry=n+m-2-k-j;
                if(ly<0||ry<0||ly>=m||ry>=m)
                    continue;
                if(s[i][ly]!=s[j][ry])
                    dp[cur^1][i][j]=0;
                else
                {
                    //printf("%d %d %d %d\n",i,ly,j,ry);
                    for(int q=0;q<2;q++)
                    {
                        for(int r=0;r<2;r++)
                        {
                            txl=i+dxl[q];
                            tyl=ly+dyl[q];
                            txr=j+dxr[r];
                            tyr=ry+dyr[r];
                            if(txl>=0&&txl<n&&tyl>=0&&tyl<m&&txr>=0&&txr<n&&tyr>=0&&tyr<m)
                            {
                                //printf("%d %d %d\n",cur,txl,txr);
                                dp[cur^1][i][j]=modAdd(dp[cur^1][i][j],dp[cur][txl][txr]);
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans=0;
    if(!((n+m)&1))
    {
        for(int i=0;i<n;i++)
            ans=modAdd(ans,dp[cur][i][i]);
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<=min(n-1,i+1);j++)
                ans=modAdd(ans,dp[cur][i][j]);
        }
    }
    printf("%I64d\n",ans);
}
 