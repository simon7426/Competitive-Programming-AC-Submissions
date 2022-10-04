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
int low[300010][4],hi[300010][4],x[100010],y[100010],ans[10];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int i,j,k;
    for(i=0;i<300010;i++)
    {
        for(j=0;j<4;j++)
        {
            low[i][j]=1e9;
            hi[i][j]=-1e9;
        }
    }
    int n=in(),m=in();
    for(i=0;i<m;i++)
    {
        x[i]=in(),y[i]=in();
        low[x[i]][0]=min(low[x[i]][0],y[i]);
        low[y[i]][1]=min(low[y[i]][1],x[i]);
        low[x[i]+y[i]][2]=min(low[x[i]+y[i]][2],x[i]);
        low[n+x[i]-y[i]][3]=min(low[n+x[i]-y[i]][3],x[i]);
        hi[x[i]][0]=max(hi[x[i]][0],y[i]);
        hi[y[i]][1]=max(hi[y[i]][1],x[i]);
        hi[x[i]+y[i]][2]=max(hi[x[i]+y[i]][2],x[i]);
        hi[n+x[i]-y[i]][3]=max(hi[n+x[i]-y[i]][3],x[i]);
    }
    int cnt;
    for(i=0;i<m;i++)
    {
        cnt=0;
        if(low[x[i]][0]<y[i]) cnt++;
        if(low[y[i]][1]<x[i]) cnt++;
        if(low[x[i]+y[i]][2]<x[i]) cnt++;
        if(low[n+x[i]-y[i]][3]<x[i]) cnt++;
        if(hi[x[i]][0]>y[i]) cnt++;
        if(hi[y[i]][1]>x[i]) cnt++;
        if(hi[x[i]+y[i]][2]>x[i]) cnt++;
        if(hi[n+x[i]-y[i]][3]>x[i]) cnt++;
        ans[cnt]++;
    }
    for(i=0;i<9;i++) printf("%d ",ans[i]);
    return 0;
}
 