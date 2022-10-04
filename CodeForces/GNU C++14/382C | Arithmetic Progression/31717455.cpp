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
int a[100010];
map<int,int> m;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),d,i,t;
    for(i=0;i<n;i++)
        a[i]=in();
    sort(a,a+n);
    if(n==1)
    {
        printf("-1\n");
        return 0;
    }
    d=1e9;
    for(i=1;i<n;i++)
    {
       // cout<<a[i]-a[i-1]<<endl;
        d=min(d,a[i]-a[i-1]);
        m[a[i]-a[i-1]]++;
        if(m[a[i]-a[i-1]]==2)
        {
            d=a[i]-a[i-1];
            break;
        }
    }
    int f=0;
    for(i=1;i<n;i++)
    {
        if((a[i-1]+d)!=a[i])
        {
            f++;
            if(a[i-1]+d+d==a[i])
                t=a[i-1]+d;
            else
                t=-1;
        }
    }
    if(f>1)
    {
        printf("0\n");
        return 0;
    }
    if(f==0)
    {
        if(d==0)
    {
        printf("1\n%d\n",a[0]);
        return 0;
    }
        if(n==2)
        {
            if(!((a[0]+a[1])&1))
            {
                printf("3\n");
                printf("%d %d %d\n",a[0]-d,(a[0]+a[1])/2,a[1]+d);
                return 0;
            }
        }
        printf("%d\n",2);
        printf("%d %d\n",a[0]-d,a[n-1]+d);
    }
    if(f==1)
    {
        if(t==-1)
            printf("0\n");
        else
            {
                printf("1\n");
                printf("%d\n",t);
            }
 
    }
}
 