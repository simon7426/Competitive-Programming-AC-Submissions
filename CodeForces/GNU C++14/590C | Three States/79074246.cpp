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
const int inf = 200000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)
 
#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
 
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; ///4 Direction
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
char s[1005][1005];
int n,m;
int dp[3][1005][1005],vis[1005][1005],mindis[3][3];
queue<pii> q;
void bfs(int k)
{
    pii a;
    int x,y;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            x=a.ff+dx[i];
            y=a.ss+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='#'&&!vis[x][y])
            {
                dp[k][x][y]=1+dp[k][a.ff][a.ss];
                vis[x][y]=1;
                q.push({x,y});
                if(s[x][y]!='.'&&s[x][y]-'1'!=k)
                {
                    //printf("%d %d %d %d\n",k,s[x][y]-'1',mindis[k][s[x][y]-'1'],dp[k][x][y]);
                    mindis[k][s[x][y]-'1']=min(mindis[k][s[x][y]-'1'],dp[k][x][y]-1);
                }
            }
        }
    }
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in();
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            mindis[i][j]=inf;
    }
    for(int k=0;k<3;k++)
    {
        mem(vis,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                    if(s[i][j]-'1'==k)
                    {
                        q.push({i,j});
                        dp[k][i][j]=0;
                        vis[i][j]=1;
                    }
                    else
                    {
                        dp[k][i][j]=inf;
                    }
                }
        }
        bfs(k);
    }
    int ans=inf;
    //for(int i=0;i<3;i++){for(int j=0;j<3;j++) printf("%d ",mindis[i][j]);printf("\n");}
    ans=min(min(mindis[0][1]+mindis[1][2],mindis[1][2]+mindis[2][0]),mindis[2][0]+mindis[0][1]);
    //printf("%d\n",ans);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        ans=min(ans,dp[0][i][j]+dp[1][i][j]+dp[2][i][j]-2);
    }
    if(ans>m*n) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}