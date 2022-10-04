#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int cnt[105];
    memset(cnt,0,sizeof cnt);
    vector<int> v;
    int n,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        cnt[t]++;
    }
    for(i=1;i<=100;i++)
    {
        if(cnt[i]>0)v.push_back(i);
    }
    if(v.size()!=2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(cnt[v[0]]==cnt[v[1]])
    {
        cout<<"YES"<<endl;
        cout<<v[0]<<" "<<v[1]<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
 
    }
    return 0;
}