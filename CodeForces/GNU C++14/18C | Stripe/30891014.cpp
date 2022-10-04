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
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
 
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
int a[100010],pre[100010],suf[100010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),i,t;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        a[i]=in();
    }
    mem(pre,0);
    mem(suf,0);
    pre[0]=a[0];
    suf[n-1]=a[n-1];
    for(i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+a[i];
        suf[n-i-1]=suf[n-i]+a[n-i-1];
    }
    //for(i=0;i<n;i++) cout<<pre[i]<<" ";cout<<endl;
    //for(i=0;i<n;i++) cout<<suf[i]<<" ";cout<<endl;
    int ans=0;
    for(i=0;i<n-1;i++)
        if(pre[i]==suf[i+1])ans++;
    printf("%d\n",ans);
    return 0;
}
 