#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int g[105][105],a[105];
vector<int> v;
main()
{
    int i,j;
    for(i=0;i<105;i++)
    {
        for(j=0;j<105;j++)
            g[i][j]=1e9;
    }
    int n,m,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a[i]=t;
        g[i][t]=1;
    }
    int k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        }
    }
    for(i=1;i<=n;i++)
        {
            if(g[i][i]>=1e9)
            {
                printf("%d\n",-1);
                return 0;
            }
            v.push_back(((g[i][i]&1)?g[i][i]:g[i][i]>>1));
        }
        t=v[0];
        int x;
        for(i=1;i<n;i++)
        {
            //cout<<t<<" "<<v[i]<<endl;
            x=__gcd(t,v[i]);
            t=(v[i]/x)*t;
        }
        printf("%d\n",t);
        return 0;
}