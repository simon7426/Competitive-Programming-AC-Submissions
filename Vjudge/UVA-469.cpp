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

int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

char g[105][105];
int vis[105][105];
int cnt;

void dfs(int x,int y)
{
    if(x<0||y<0||g[x][y]==0) return;
    if(vis[x][y]!=0||g[x][y]!='W') return;
    vis[x][y]=1;
    cnt++;
    for(int i=0;i<8;i++) dfs(x+dx[i],y+dy[i]);
}

main()
{
        int tcc,i,n,x,y;
        char s[105];
        scanf("%d ",&tcc);
        while(tcc--)
        {
            n=0;
            memset(g,0,sizeof g);
            while(gets(s))
            {
                if(s[0]=='\0')
                    break;
                if(s[0]=='L'||s[0]=='W')
                {
                    sscanf(s,"%s",g[n]);
                    n++;
                }
                else
                {
                    sscanf(s,"%d %d",&x,&y);
                    cnt=0;
                    memset(vis,0,sizeof vis);
                    dfs(x-1,y-1);
                    printf("%d\n",cnt);
                }
            }
            if(tcc)printf("\n");
        }
}
