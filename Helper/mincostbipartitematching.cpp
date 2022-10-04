#include<bits/stdc++.h>
using namespace std;
const int sz=25;
int cost[sz][sz];
int lmate[sz];
int rmate[sz];
int n;
int MinCostMatching()
{
    int u[sz];
    int v[sz];
    for(int i=0;i<n;i++)
    {
        u[i]=cost[i][0];
        for(int j=1;j<n;j++)
            u[i]=min(u[i],cost[i][j]);
    }
    for(int j=0;j<n;j++)
    {
        v[j]=cost[0][j]-u[0];
        for(int i=1;i<n;i++)
            v[j]=min(v[j],cost[i][j]-u[i]);
    }
    memset(lmate,-1,sizeof(lmate));
    memset(rmate,-1,sizeof(rmate));
    int mated=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(rmate[j]!=-1) continue;
            if(cost[i][j]-u[i]-v[j]==0)
            {
                lmate[i]=j;
                rmate[j]=i;
                mated++;
                break;
            }
        }
    }
    int dist[n];
    int dad[n];
    int seen[n];
    while(mated<n)
    {
        int s=0;
        while(lmate[s]!=-1) s++;

        memset(dad,-1,sizeof(dad));
        memset(seen,0,sizeof(seen));
        for(int k=0;k<n;k++)
            dist[k]=cost[s][k]-u[s]-v[k];
        int j=0;
        while(true)
        {
            j=-1;
            for(int k=0;k<n;k++)
            {
                if(seen[k])continue;
                if(j==-1||dist[k]<dist[j]) j=k;
            }
            seen[j]=1;
            if(rmate[j]==-1)break;

            const int i=rmate[j];
            for(int k=0;k<n;k++)
            {
                if(seen[k])continue;
                const int new_dist=dist[j]+cost[i][k]-u[i]-v[k];
                if(dist[k]>new_dist)
                {
                    dist[k]=new_dist;
                    dad[k]=j;
                }
            }
        }

        for(int k=0;k<n;k++)
        {
            if(k==j||!seen[k])continue;
            const int i=rmate[k];
            v[k]+=dist[k]-dist[j];
            u[i]-=dist[k]-dist[j];
        }
        u[s]+=dist[j];

        while(dad[j]>=0)
        {
            const int d=dad[j];
            rmate[j]=rmate[d];
            lmate[rmate[j]]=j;
            j=d;
        }
        rmate[j]=s;
        lmate[s]=j;

        mated++;
    }
    int value=0;
    for(int i=0;i<n;i++)
        value+=cost[i][lmate[i]];
    return value;
}

main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    //printf("%d\n",n);
    int cnt=MinCostMatching();
    printf("%d\n",cnt);
}
/*
3
1500 4000 4500
2000 6000 3500
2000 4000 2500
*/
