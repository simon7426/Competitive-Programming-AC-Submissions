#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v[1010];
int vis[1010],dis[1010],a[110];
void bfs(int n)
{
    int x,i,y;
    memset(vis,0,sizeof vis);
    vis[n]=1;
    dis[n]++;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0;i<v[x].size();i++)
        {
            y=v[x][i];
            if(!vis[y])
            {
                vis[y]=1;
                dis[y]++;
                q.push(y);
            }
        }
    }

}
main()
{
    int tc,tcc,i,j,n,m,k,s,t;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        for(i=0;i<1010;i++) v[i].clear();
        scanf("%d %d %d",&k,&n,&m);
        for(i=0;i<k;i++)
            scanf("%d",a+i);
        for(i=0;i<m;i++)
            {
                scanf("%d %d",&s,&t);
                v[s].push_back(t);
            }
        memset(dis,0,sizeof dis);
        for(i=0;i<k;i++)
        {
            //cout<<a[i]<<endl;
            bfs(a[i]);
        }
        int cnt=0;
        for(i=1;i<=n;i++)
            if(dis[i]==k) cnt++;
        printf("Case %d: %d\n",tc,cnt);
    }
    return 0;
}
