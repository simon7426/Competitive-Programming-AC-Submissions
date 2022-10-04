#include<bits/stdc++.h>
using namespace std;

bool v[100010];

main()
{
    int i,j,k=1,n=500;
    memset(v,0,sizeof(v));
    for(i=2;i<=n;i+=k)
    {
        if(v[i]==0)
        {
            for(j=i*i;j<=n;j+=i)
                v[j]=1;
        }
        if(i==3) k=2;
    }
    for(i=2;i<=500;i++)
        if(v[i]==0)
        cout<<i<<" ";
}
