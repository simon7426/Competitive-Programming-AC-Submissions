#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int,int> > g[30050];
int dis[30050],vis[30050];

void bfs(int n)
{
    memset(dis,0,sizeof dis);
    memset(vis,0,sizeof vis);
    int i,x;
    pair<int,int> y;
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
            if(!vis[y.first])
            {
                vis[y.first]=1;
                dis[y.first]=dis[x]+y.second;
                q.push(y.first);
            }
        }
    }
}
int main()
{
    int tc,tcc,i,n,s,t,w;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        for(i=0;i<30050;i++) g[i].clear();
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&s,&t,&w);
            g[s].push_back(make_pair(t,w));
            g[t].push_back(make_pair(s,w));
        }
        bfs(0);
        int ma=0;
        t=0;
        for(i=0;i<n;i++) {if(ma<dis[i]){ma=dis[i];t=i;}}
        bfs(t);
        ma=0;
        for(i=0;i<n;i++)
            ma=max(ma,dis[i]);
        printf("Case %d: %d\n",tc,ma);
    }
    return 0;
}
