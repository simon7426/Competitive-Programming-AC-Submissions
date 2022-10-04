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
 
int dp[2][55][55],dis[2][55][55],c[55][55];
queue<pair<int,pii> > q;
pair<int,pii> fro;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    c[0][0]=1;
    for(int i=1;i<55;i++)
    {
        c[i][0]=1;
        for(int j=1;j<55;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
    int n=in(),k=in(),x,n1=0,n2=0;
    for(int i=0;i<n;i++)
    {
        x=in();
        if(x==50) n1++;
        else n2++;
    }
    mem(dis,-1);
    dis[0][n1][n2]=0;
    dp[0][n1][n2]=1;
    q.push({0,{n1,n2}});
    int nxtpos,curf,curt,pos,nxtf,nxtt;
    while(!q.empty())
    {
        fro=q.front();
        q.pop();
        pos=fro.ff;
        curf=fro.ss.ff;
        curt=fro.ss.ss;
        for(int i=0;i<=curf;i++)
        {
            if(i*50>k) break;
            for(int j=0;j<=curt;j++)
            {
                if(i+j==0) continue;
                if(i*50+j*100>k) break;
                nxtf=n1-curf+i;
                nxtt=n2-curt+j;
                nxtpos=1-pos;
                if(dis[nxtpos][nxtf][nxtt]==-1)
                {
                    dis[nxtpos][nxtf][nxtt]=dis[pos][curf][curt]+1;
                    dp[nxtpos][nxtf][nxtt]=modMul(dp[pos][curf][curt],modMul(c[curf][i],c[curt][j]));
                    q.push({nxtpos,{nxtf,nxtt}});
                }
                else if(dis[nxtpos][nxtf][nxtt]==dis[pos][curf][curt]+1)
                {
                    dp[nxtpos][nxtf][nxtt]=modAdd(dp[nxtpos][nxtf][nxtt],modMul(dp[pos][curf][curt],modMul(c[curf][i],c[curt][j])));
                }
            }
        }
    }
    printf("%d\n%d\n",dis[1][n1][n2],dp[1][n1][n2]);
}