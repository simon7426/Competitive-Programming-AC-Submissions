#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
main()
{
    int n,i,t;
    cin>>n;
    int a[n+1],cnt[n+1];
    vi x,y;
    memset(cnt,0,sizeof cnt);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=n)cnt[a[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        if(cnt[i]==0) y.push_back(i);
    }
    int j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>n){a[i]=y[j++];continue;}
        cnt[a[i]]--;
        if(cnt[a[i]]>=1) a[i]=y[j++];
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}