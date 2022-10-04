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
#define pb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'
 
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))
int vis[25][25];
char s[25][25];
int n=0,w,h;
int X[4]={1,-1,0,0};
int Y[4]={0,0,1,-1};
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int dx=x+X[i];
        int dy=y+Y[i];
        if(((dx >= 0 && dx < h) && (dy >= 0 && dy < w)) && s[dx][dy]=='.' && !vis[dx][dy])
        {
            //printf("%d %d %c %d\n",dx,dy,s[dx][dy],vis[dx][dy]);
            n++;
            vis[dx][dy]=1;
            dfs(dx,dy);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int i,j,k,ip,cnt,x,y;
    for(k=0;k<t;k++)
    {
        cnt=0;
        memset(vis,0,sizeof vis);
        scanf("%d %d",&w,&h);
        for(i=0;i<h;i++)
        {
            getchar();
            for(j=0;j<w;j++)
            {
            scanf("%c",&s[i][j]);
            if(s[i][j]=='@')
            {
                x=i;
                y=j;
                //printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            }
        }
        n=1;
        dfs(x,y);
        printf("Case %d: %d\n",k+1,n);
    }
    return 0;
}
 