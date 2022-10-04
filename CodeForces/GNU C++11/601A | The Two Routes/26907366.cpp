#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int gr[410][410];
int n,m,vis[410],dis[410];
 
void bfs(int k)
{
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        //cout<<x<<"-";
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&x!=i&&gr[x][i]==k)
                {
                    //cout<<i<<" ";
                    vis[i]=1;
                    q.push(i);
                    dis[i]=dis[x]+1;
                }
        }
        //cout<<endl;
}
}
main()
{
    int l,r,i;
    memset(gr,0,sizeof gr);
    memset(vis,0,sizeof vis);
    memset(dis,-1,sizeof dis);
    dis[1]=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        gr[l][r]=1;
        gr[r][l]=1;
    }
   /* for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<gr[i][j]<< " ";
        cout<<endl;
    }*/
    int k=!(gr[1][n]);
    bfs(k);
    //for(i=1;i<=n;i++)
        //cout<<dis[i]<<" ";
    //cout<<endl;
    cout<<((dis[n]==-1)?-1:dis[n])<<endl;
}