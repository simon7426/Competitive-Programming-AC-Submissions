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

//#define PB push_back
#define PB emplace_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

char a[105][105];
int n,vis[105][105],m;

void dfs(int x,int y)
{
    if(x<0||x>n-1||y<0||y>m-1) return;
    if(a[x][y]=='*') return;
    vis[x][y]=1;
    for(int i=0;i<8;i++)
    {
        if(!vis[x+dx[i]][y+dy[i]])
            dfs(x+dx[i],y+dy[i]);
    }

}
main()
{
    int i,t=0,j;
    while(scanf("%d %d ",&n,&m)==2)
    {
        if(n==0&&m==0) break;
        for(i=0;i<n;i++)
            gets(a[i]);
        /*for(i=0;i<n;i++)
            puts(a[i]);*/
        mem(vis,0);
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='@'&&vis[i][j]==0)
                {   cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

