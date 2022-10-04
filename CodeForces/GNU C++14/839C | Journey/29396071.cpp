#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<int> g[100010];
int vis[100010];
int dis[100010];
int deg[100010];
double prob[100010];
 
void dfs(int x)
{
    int v;
    //cout<<x<<" "<<deg[x]<<endl;
    vis[x]=2;
    for(int i=0;i<g[x].size();i++)
    {
        v=g[x][i];
        if(!vis[v])
        {
            vis[x]=1;
            --deg[v];
            prob[v]=prob[x]/deg[x];
            dis[v]=dis[x]+1;
            dfs(v);
        }
    }
}
 
main()
{
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    memset(deg,0,sizeof deg);
    //memset(prob,0,sizeof prob);
    int n,i,t,a,b;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g[b].push_back(a);
        g[a].push_back(b);
        ++deg[a];
        ++deg[b];
    }
    prob[1]=1;
    dfs(1);
    /*for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<vis[i]<<" "<<dis[i]<<" "<<prob[i]<<endl;
    }*/
    double ans=0;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==2) ans+=(double)dis[i]*prob[i];
    }
    printf("%.09f\n",ans);
}