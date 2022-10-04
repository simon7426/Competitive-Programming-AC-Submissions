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
vi lucky;
map<int,int> m;
int f[13],b[13],d[13];
void genluck(int x)
{
    lucky.pb(x);
    m[x]=1;
    if(x>100000000) return;
    genluck(x*10+4);
    genluck(x*10+7);
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    genluck(4);
    genluck(7);
    sort(lucky.begin(),lucky.end());
    f[0]=1;
    for(int i=1;i<13;i++)
        f[i]=i*f[i-1];
    int n=in(),k=in();
    if(n<13&&k>f[n])
    {
        printf("-1\n");
        return 0;
    }
    int l,r,x,j;
    for(r=1;r<13;r++)
    {
        if(f[r]>=k) break;
    }
    l=n-r;
    int res=0;
    while(res<lucky.size()&&lucky[res]<=l) res++;
    k--;
    for(int i=1;i<=r;i++)
    {
        x=(k+f[r-i])/f[r-i];
        k%=f[r-i];
        j=0;
        while(x)
        {
            if(!d[++j])x--;
        }
        b[i]=j;
        d[j]=1;
    }
    for(int i=1;i<=r;i++)
    {
        if(m[i+l]&&m[b[i]+l]) res++;
    }
    printf("%d\n",res);
    return 0;
}
 