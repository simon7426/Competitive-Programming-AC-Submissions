#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
vector<int> a[55];
int vis[55];
ll ans=1;
void dfs(int i)
{
    vis[i]=1;
    for(int j=0;j<a[i].size();j++)
    {
        if(vis[a[i][j]]==0)
        {
            ans*=2L;
            dfs(a[i][j]);
        }
    }
}
main()
{
    int n,m,i,t,x,y;
    scanf("%d %d",&n,&m);
    memset(vis,0,sizeof vis);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    printf("%I64d\n",ans);
    return 0;
}