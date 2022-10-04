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
bool prime[100010];
vi v[100010];
int ans[100010];
void f(int x)
{
    //printf("%d\n",x);
    int i,y=-1;
    for(i=0;i<v[x].size();i++)
        y=max(y,ans[v[x][i]]);
    for(i=0;i<v[x].size();i++)
        {
            ans[v[x][i]]=y+1;
            //printf("%d %d %d\n",x,v[x][i],ans[v[x][i]]);
        }
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int i,j,k=1,sq=sqrt(100010)+10;
    mem(prime,1);
    for(i=2;i<100010;i+=k)
    {
        if(prime[i]==1)
        {
            v[i].pb(i);
            for(j=i+i;j<100010;j+=i)
                prime[j]=0,v[j].pb(i);
        }
        if(i==3) k=2;
    }
    int n=in(),t;
    mem(ans,0);
    for(i=0;i<n;i++)
    {
        t=in();
        f(t);
    }
    int res=0;
    for(i=0;i<100010;i++) res=max(res,ans[i]);
    res=max(1,res);
    printf("%d\n",res);
}
 