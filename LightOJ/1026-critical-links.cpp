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

#define PB push_back
//#define PB emplace_back
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

vi g[10100];
vii a;
int low[10100],vis[10100],n,m,cnt,rc,r,p[10100];

void dfs(int u)
{
    low[u]=vis[u]=cnt++;
    //printf("%d %d\n",u,cnt);
    for(int j=0;j<g[u].size();j++)
    {
        int v=g[u][j];
        if(!vis[v])
        {
            p[v]=u;
            if(u==r) rc++;
            dfs(v);
            if(low[v]>vis[u])
                a.PB(MP(min(u,v),max(u,v)));
            low[u]=min(low[v],low[u]);
        }
        else if(v!=p[u])
            low[u]=min(low[u],vis[v]);
    }

}

main()
{
    int tc,tcc,i,u,v,j;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        a.clear();
        for(i=0;i<10010;i++) g[i].clear();
        memset(vis,0,sizeof vis);
        memset(low,0,sizeof low);
        memset(p,0,sizeof p);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d (%d)",&u,&n);
            for(j=0;j<n;j++)
                {
                    scanf("%d",&v);
                    g[u].push_back(v);
                }
        }
        for(i=0;i<m;i++)
        {
            if(vis[i]==0)
            {
            r=i;
            rc=0;
            cnt=0;
            //printf("X");
            dfs(i);
            }
        }

        printf("Case %d:\n",tc);
        printf("%d critical links\n",a.size());
        sort(a.begin(),a.end());
        for(i=0;i<a.size();i++)
            printf("%d - %d\n",a[i].F,a[i].S);
    }
    return 0;
}
