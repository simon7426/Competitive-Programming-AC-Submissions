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
char s[1000010];
int n;
vii g[1000010];
int getnum(int &x)
{
    int ret=0;
    for(;x<n;x++)
    {
        if(s[x]==',') break;
        ret=ret*10+(s[x]-'0');
    }
    return ret;
}
int dfs(int x,int fpos)
{
    int i;
    for(i=fpos;i<n;i++)
    {
        if(s[i]==',')
        {
            g[x].pb({fpos,i-1});
            break;
        }
    }
    i++;
    int dep=getnum(i);
    i++;
    for(int j=1;j<=dep;j++)
    {
        i=dfs(x+1,i);
    }
    return i;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    scanf("%s",s);
    n=strlen(s);
    int cur=0;
    while(cur<n)
    {
        cur=dfs(0,cur);
    }
    int ans=0;
    for(int i=0;i<1000010;i++)
    {
        if(g[i].size()) ans=i;
        else break;
    }
    printf("%d\n",ans+1);
    int f;
    pii k;
    for(int i=0;i<=ans;i++)
    {
        f=1;
        for(int j=0;j<g[i].size();j++)
        {
            if(f) f=0;
            else printf(" ");
            k=g[i][j];
            for(int x=k.ff;x<=k.ss;x++)
                printf("%c",s[x]);
        }
        printf("\n");
    }
}