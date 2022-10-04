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
char s[510][510];
int n,m,r1,c1,r2,c2,f=0;
int vis[510][510];
void dfs(int x,int y)
{
    //printf("%d %d\n",x,y);
    int i,x1,y1;
    vis[x][y]=1;
    if(s[x][y]=='X'&&(x!=r1||y!=c1)) return;
    for(i=0;i<4;i++)
    {
        x1=x+dx[i];
        y1=y+dy[i];
        if(x1>=0&&x1<n&&y1>=0&&y1<m)
        {
        if(vis[x1][y1]==0)
            dfs(x1,y1);
        }
    }
 
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int i,j;
    n=in(),m=in();
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    r1=in(),c1=in();
    r2=in(),c2=in();
    --r1,--c1,--r2,--c2;
    mem(vis,0);
    dfs(r1,c1);
    int x,y;
    if(vis[r2][c2]==0)
    {
        printf("NO\n");
        return 0;
    }
    int cnt=0,x1,y1;
    if(abs(r1-r2)+abs(c1-c2)==1)
    {
        if(s[r2][c2]=='X')
        {
            printf("YES\n");
            return 0;
        }
        else
        {
        for(i=0;i<4;i++)
        {
            x1=r2+dx[i];
            y1=c2+dy[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m)
            {
                if(s[x1][y1]=='.')
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
        printf("NO\n");
        return 0;
        }
    }
    if(r1==r2&&c1==c2)
    {
        for(i=0;i<4;i++)
        {
            x1=r2+dx[i];
            y1=c2+dy[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m)
            {
                if(s[x1][y1]=='.')
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
        printf("NO\n");
        return 0;
    }
    if(s[r2][c2]=='X'&&vis[r2][c2]==1)
    {
        printf("YES\n");
        return 0;
    }
    if(s[r2][c2]=='.'&&vis[r2][c2]==1)
    {
        for(i=0;i<4;i++)
        {
            x1=r2+dx[i];
            y1=c2+dy[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m)
            {
                if(s[x1][y1]=='.')
                {
                    cnt++;
                }
            }
        }
        if(cnt>=2)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}
 