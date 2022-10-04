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
//typedefs
typedef long long int ll;
typedef vector<int> vi;
vi v[150100];
int vis[150100];
ll vc,eg;
void dfs(int i)
{
    vis[i]=1;
    vc++;
    eg+=v[i].size();
    for(int j=0;j<v[i].size();j++)
    {
        if(vis[v[i][j]]==0)
            dfs(v[i][j]);
    }
}
main()
{
    int n,m,s,t,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&s,&t);
        v[s].push_back(t);
        v[t].push_back(s);
    }
    memset(vis,0,sizeof vis);
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0&&v[i].size()!=0)
        {
            vc=0;
            eg=0;
            dfs(i);
           
            if(eg!=(vc*(vc-1)))
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}