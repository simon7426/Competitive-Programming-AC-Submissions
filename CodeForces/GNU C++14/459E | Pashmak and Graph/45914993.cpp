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
vii edge[100010];
int dp[300010],tmp[300010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int x,y,z,i,j,si;
    int n=in(),m=in();
    for(i=0;i<m;i++)
    {
        x=in(),y=in(),z=in();
        edge[z].pb(mp(x,y));
    }
    mem(dp,0);
    mem(tmp,0);
    for(i=0;i<100010;i++)
    {
        if(edge[i].empty()) continue;
        si=edge[i].size();
        for(j=0;j<si;j++) tmp[edge[i][j].ss]=0;
        for(j=0;j<si;j++)
        {
            tmp[edge[i][j].ss]=max(tmp[edge[i][j].ss],dp[edge[i][j].ff]+1);
        }
        for(j=0;j<si;j++)
        {
            dp[edge[i][j].ss]=max(tmp[edge[i][j].ss],dp[edge[i][j].ss]);
        }
    }
    int ans=0;
    for(i=0;i<300010;i++)
    {
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
}
 