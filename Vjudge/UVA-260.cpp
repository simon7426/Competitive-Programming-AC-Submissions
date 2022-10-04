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

int dx[] = {+1, 0, -1, 0, +1, -1};
int dy[] = {0, +1, 0, -1, +1, -1};

int n,f,vis[205][205];
char a[205][205];

void dfs(int x,int y)
{
    if(x<0||y<0||a[x][y]==0) return;
    if(a[x][y]=='w') return;
    vis[x][y]=1;
    //printf("%d %d %d %d\n",x,y,n-1,f);
    if(x==n-1) {f=1;return;}
    for(int i=0;i<6;i++)
        {if(!vis[x+dx[i]][y+dy[i]])
            dfs(x+dx[i],y+dy[i]);
        }
}

main()
{
    int i,j,t=1;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        mem(a,0);
        for(i=0;i<n;i++)
        {
            getchar();
            for(j=0;j<n;j++)
                scanf("%c",&a[i][j]);
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }*/
        f=0;
        for(i=0;i<n;i++)
        {
            if(a[0][i]=='b')
            {
                //printf("%d ",i);
                mem(vis,0);
                dfs(0,i);
            }
        }
        printf("%d %c\n",t++,((f==1)?'B':'W'));
    }
    return 0;
}
