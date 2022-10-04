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
int n,m,d[100010],s[100010],dp[100010],vis[100010];
 
bool sol(int x)
{
    mem(dp,0);
    mem(vis,0);
    int i,cnt=0;
    for(i=x;i>0;i--)
    {
        if(vis[d[i]]==0&&d[i]!=0)
        {
            vis[d[i]]=1;
            dp[i]=s[d[i]];
            cnt++;
        }
    }
    //cout<<cnt<<endl;
    //for(i=1;i<=x;i++) cout<<dp[i]<<" "; cout<<endl;
    if(cnt<m) return false;
    cnt=0;
    for(i=1;i<=x;i++)
    {
        //cout<<cnt<<" ";
        if(dp[i]==0)
            cnt++;
        else
            cnt-=dp[i];
        if(cnt<0)
        {
            //cout<<cnt<<endl;
            return false;
        }
    }
    return true;
}
 
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in();
    int i,t;
    for(i=1;i<=n;i++) d[i]=in();
    for(i=1;i<=m;i++) s[i]=in();
    int low=1,high=n,mid;
    int ans=-1;
    while(low<high)
    {
        mid=(low+high+1)>>1;
        //cout<<low<<" "<<mid<<" "<<high<<endl;
        if(!sol(mid))
        {
            low=mid;
        }
        else
        {
            ans=mid;
            high=mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
 