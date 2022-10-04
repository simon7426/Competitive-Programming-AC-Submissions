#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
vector<int> g[4010];
int v[4005][4005];
int deg[4010];
main()
{
    int n,m,i,j,k,t,a,b,mi=INT_MAX;
    memset(v,0,sizeof v);
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        v[a][b]=1;
        v[b][a]=1;
        deg[a]++;
        deg[b]++;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<g[i].size();j++)
        {
            a=g[i][j];
            for(k=0;k<g[a].size();k++)
            {
                b=g[a][k];
                if(v[i][b]==1)
                {
                    //cout<<i<<" "<<a<<" "<<b<<" "<<mi<<" "<<deg[i]<<" "<<deg[a]<<" "<<deg[b]<<endl;
                    mi=min(mi,deg[i]+deg[a]+deg[b]-6);
                }
            }
        }
    }
    if(mi==INT_MAX)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",mi);
    return 0;
}