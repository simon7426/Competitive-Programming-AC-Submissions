#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
#include<iterator>
#include<set>
using namespace std;
int am[410][410];
int n,m;
int bfs(int k)
{
    //cout<<k<<endl;
    int s,t;
    bool f=0;
    int vis[410];
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        t=q.front();
         q.pop();
         //cout<<t<<" ";
        if(t==n){f=1; break;}
        for(int i=1;i<=n;i++)
        {
            if(am[t][i]==k&&t!=i&&!vis[i])
            {
                vis[i]=1+vis[t];
                q.push(i);
            }
        }
    }
   // cout<<endl;
    return (f==1)?vis[n]-1:-1;
}
main()
{
    int i,a,b,j;
    cin>>n>>m;
    memset(am,0,sizeof am);
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        am[a][b]=1;
        am[b][a]=1;
    }

   /* for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<am[i][j]<<" ";
        cout<<endl;
    }*/
    if(am[1][n]==0)
        cout<<bfs(1)<<endl;
    else
        cout<<bfs(0)<<endl;
    return 0;
}
