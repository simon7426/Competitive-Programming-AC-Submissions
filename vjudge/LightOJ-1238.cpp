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

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int m,n;
char a[25][25];
int dis[25][25];

void dfs(int x,int y,int cnt)
{
    if(x<0||x>=m||y<0||y>=n||a[x][y]=='m'||a[x][y]=='#') return;
    if(dis[x][y]!=-1)
    {
        if(cnt>=dis[x][y]) return;
        else dis[x][y]=cnt;
    }
    if(dis[x][y]==-1) dis[x][y]=cnt;
    for(int i=0;i<4;i++)
        dfs(x+dx[i],y+dy[i],cnt+1);
}

main()
{
    int i,t,tc,tcc,j,x[4],y[4];
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
        {
            getchar();
            for(j=0;j<n;j++)
                {
                    scanf("%c",&a[i][j]);
                    if(a[i][j]=='a') x[0]=i,y[0]=j;
                    else if(a[i][j]=='b') x[1]=i,y[1]=j;
                    else if(a[i][j]=='c') x[2]=i,y[2]=j;
                    else if(a[i][j]=='h') x[3]=i,y[3]=j;
        }
        }
        /*for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
        for(i=0;i<4;i++)
            cout<<x[i]<<" "<<y[i]<<endl;*/
            int mi=0;
            for(i=0;i<3;i++)
            {
                memset(dis,-1,sizeof dis);
                //dis[x[i]][y[i]]=0;
                dfs(x[i],y[i],0);
               /* printf("\n");
                for(int k=0;k<m;k++)
                {
                    for(j=0;j<n;j++)
                        printf("%d ",dis[k][j]);
                    printf("\n");
                }
                printf("\n");*/
                mi=max(mi,dis[x[3]][y[3]]);
            }
            printf("Case %d: %d\n",tc,mi);
    }
}
