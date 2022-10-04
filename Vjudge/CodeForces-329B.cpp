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
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int dis[1005][1005],vis[1005][1005];
string s[1005];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    int r,c;
    cin>>r>>c;
    int i,j,k;
    for(i=0;i<r;i++)
        cin>>s[i];
    int f=0,x,y,x1,y1;
    for(i=0;i<r;i++)
    {
        if(f==1) break;
        for(j=0;j<c;j++)
        {
            if(s[i][j]=='E')
            {
               f=1;
               x=i;
               y=j;
               break;
            }
        }
    }
    for(f=0,i=0;i<r;i++)
    {
        if(f==1) break;
        for(j=0;j<c;j++)
        {
            if(s[i][j]=='S')
            {
               f=1;
               x1=i;
               y1=j;
               break;
            }
        }
    }
    mem(vis,0);
    mem(dis,0);
    queue<pii> q;
    q.push(mp(x,y));
    vis[x][y]=1;
    pii v;
    while(!q.empty())
    {
        v=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            x=v.ff+dx[i];
            y=v.ss+dy[i];
            if(x<0||y<0||x>=r||y>=c) continue;
            if(s[x][y]=='T') continue;
            if(vis[x][y])continue;
            vis[x][y]=1;
            dis[x][y]=1+dis[v.ff][v.ss];
            q.push(mp(x,y));
        }
    }
    int mi=dis[x1][y1],ans=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(s[i][j]=='E'||s[i][j]=='T'||s[i][j]=='S'||s[i][j]=='0') continue;
            if(dis[i][j]<=mi&&vis[i][j]==1)
                ans+=(s[i][j]-'0');
        }
    }
    cout<<ans<<endl;
}

