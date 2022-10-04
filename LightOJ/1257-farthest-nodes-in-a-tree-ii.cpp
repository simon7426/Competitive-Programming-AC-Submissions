#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<int,int> > v[30050];
int vis[30050],dis[30050],dis2[30050];
void bfs(int n)
{
    int x,i,z;
    pair<int,int> y;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    int ma=0;
    vis[n]=1;
    dis[n]=0;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0;i<v[x].size();i++)
        {
            y=v[x][i];
            if(!vis[y.first])
            {
                vis[y.first]=1;
                dis[y.first]=dis[x]+y.second;
                q.push(y.first);
            }
        }
    }
}
void bfs2(int n)
{
    int x,i,z;
    pair<int,int> y;
    memset(vis,0,sizeof vis);
    memset(dis2,0,sizeof dis);
    int ma=0;
    vis[n]=1;
    dis2[n]=0;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0;i<v[x].size();i++)
        {
            y=v[x][i];
            if(!vis[y.first])
            {
                vis[y.first]=1;
                dis2[y.first]=dis2[x]+y.second;
                q.push(y.first);
            }
        }
    }
}
main()
{
    int tc,tcc,i,j,n,m,k,s,t,w;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        for(i=0;i<30050;i++) v[i].clear();
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
            {
                scanf("%d %d %d",&s,&t,&w);
                v[s].push_back(make_pair(t,w));
                v[t].push_back(make_pair(s,w));
            }
        bfs(0);
        int ma=0;
        t=0;
        for(i=0;i<n;i++)
        {
            if(ma<=dis[i])
            {
                ma=dis[i];
                t=i;
            }
        }
        bfs(t);
        ma=0;
        t=0;
        for(i=0;i<n;i++)
        {
            if(ma<=dis[i])
            {
                ma=dis[i];
                t=i;
            }
        }
        bfs2(t);
        printf("Case %d:\n",tc);
        for(i=0;i<n;i++)
            printf("%d\n",max(dis[i],dis2[i]));
    }
    return 0;
}

