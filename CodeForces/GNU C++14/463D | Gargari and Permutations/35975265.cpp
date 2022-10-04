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
int pos[5][1010],ar[5][1010];
vi g[1010];
int vis[1010],val[1010];
void dfs(int x)
{
    //printf("%d\n",x);
    vis[x]=1;
    val[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        if(!vis[g[x][i]])
            dfs(g[x][i]);
        val[x]=max(val[g[x][i]]+1,val[x]);
    }
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),k=in(),i,t,j;
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {
            ar[i][j]=in();
            pos[i][ar[i][j]]=j+1;
        }
    }
    /*for(i=0;i<k;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",pos[i][j]);
        printf("\n");
    }*/
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)continue;
            int f=1;
            for(int x=0;x<k;x++)
            {
                if(pos[x][i]>=pos[x][j])
                    {
                        //printf("%d %d %d\n",x+1,i,j);
                        f=0;
                    }
            }
            if(f)
                {
                    //printf("%d %d\n",i,j);
                    g[i].pb(j);
                }
        }
    }
    mem(vis,0);
    mem(val,0);
    for(i=1;i<=n;i++)
        {
 
            if(!vis[i])
            {
                    dfs(i);
                    //printf("%d\n",i);
            }
        }
    printf("%d\n",*max_element(val+1,val+n+1));
    return 0;
}
 