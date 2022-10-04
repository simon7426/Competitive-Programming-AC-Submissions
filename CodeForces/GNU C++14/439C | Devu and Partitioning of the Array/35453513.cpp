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
vi odd,even,ans[100010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),k=in(),p=in(),i,t;
    for(i=0;i<n;i++)
    {
        t=in();
        if(t&1) odd.pb(t);
        else even.pb(t);
    }
    if(odd.size()<k-p)
    {
        printf("NO\n");
        return 0;
    }
    for(i=0;i<k-p;i++)
        {
            ans[i].pb(odd.back());
            odd.pop_back();
        }
    if(odd.size()&1)
    {
        printf("NO\n");return 0;
    }
    if(even.size()+(odd.size()/2)<p)
    {
        printf("NO\n");return 0;
    }
    for(i=k-p;i<k-1;i++)
    {
        if(!even.empty())
        {
            ans[i].pb(even.back());
            even.pop_back();
        }
        else if(!odd.empty())
        {
            ans[i].pb(odd.back());
            odd.pop_back();
            ans[i].pb(odd.back());
            odd.pop_back();
        }
    }
    while(1)
    {
        if(!even.empty())
        {
            ans[k-1].pb(even.back());
            even.pop_back();
        }
        else if(!odd.empty())
        {
            ans[k-1].pb(odd.back());
            odd.pop_back();
            ans[k-1].pb(odd.back());
            odd.pop_back();
        }
        else break;
    }
    printf("YES\n");
    for(i=0;i<k;i++)
    {
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
}
 