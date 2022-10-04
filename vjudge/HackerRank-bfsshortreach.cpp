#include<bits/stdc++.h>
using namespace std;
int n,m,s;
vector<int> g[100010];
int vis[100010],dis[100010];
void bfs(int x)
{
    int i,v,t;
    memset(vis,0,sizeof vis);
    memset(dis,-1,sizeof dis);
    queue<int> q;
    vis[x]=1;
    dis[x]=0;
    q.push(x);
    while(!q.empty())
    {
        v=q.front();
        q.pop();
        for(i=0;i<g[v].size();i++)
        {
            t=g[v][i];
            if(!vis[t])
            {
                vis[t]=1;
                dis[t]=1+dis[v];
                q.push(t);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i==s)
            continue;
        cout<<((dis[i]==-1)? -1:dis[i]*6)<<" ";
    }
    cout<<endl;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        for(int i=0;i<1010;i++)
            g[i].clear();
        cin>>n>>m;
        int i,j,u,v;
        for(i=0;i<m;i++)
        {
            cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        }
        cin>>s;
        bfs(s);
    }
}
