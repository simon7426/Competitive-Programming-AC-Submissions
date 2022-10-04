#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
main()
{
    vector<int> v;
    int a[20010],ans[20010];
    int j,i,n,m,b,c,s,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    j=sqrt(n);
    for(i=1;i<=j;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n) v.push_back(n/i);
        }
    }
    s=-1e9;
    m=v.size();
    for(i=0;i<m;i++)
    {
        t=v[i];
        if(n/t<3)
            {continue;}
        memset(ans,0,sizeof ans);
        for(j=0;j<n;j++)
        {
            ans[j%t]+=a[j];
           // cout<<a[j-1]<<" "<<ans[n%t]<<endl;
        }
        for(j=0;j<t;j++)
            s=max(s,ans[j]);
    }
    cout<<s<<endl;
}