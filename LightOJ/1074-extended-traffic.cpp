#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> g[105];
int dis[105],dis2[105],vis[105];

void bfs(int n)
{
    memset(dis,0,sizeof dis);
    memset(vis,0,sizeof vis);
    int i,x,y;
    queue<int> q;
    q.push(n);
    vis[n]=1;
    dis[n]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(i=0;i<g[x].size();i++)
        {
            y=g[x][i];
            if(!vis[y])
            {
                vis[y]=1;
                dis[y]=dis[x]+1;
                q.push(y);
            }
        }
    }
}

void bfs2(int n)
{
    memset(dis2,0,sizeof dis);
    memset(vis,0,sizeof vis);
    int i,x,y;
    queue<int> q;
    q.push(n);
    vis[n]=1;
    dis2[n]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(i=0;i<g[x].size();i++)
        {
            y=g[x][i];
            if(!vis[y])
            {
                vis[y]=1;
                dis2[y]=dis2[x]+1;
                q.push(y);
            }
        }
    }
}

main()
{
    int tcc,tc,n,m,i,j,s,t;
    cin>>tcc;
    for(tc=1;tc<=tcc;tc++)
    {
        for(i=0;i<105;i++) g[i].clear();
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&s,&t);
            g[s].push_back(t);
            g[t].push_back(s);
        }
        scanf("%d %d",&s,&t);
        bfs(s);
        bfs2(t);
        int ma=0;
        for(i=0;i<n;i++)
        {
            ma=max(ma,dis[i]+dis2[i]);
        }
        printf("Case %d: %d\n",tc,ma);
    }
    return 0;
}
