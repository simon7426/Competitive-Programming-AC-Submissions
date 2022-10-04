#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    ll n,i,t,k,s=-1;
    cin>>n>>k;
    ll a[n],cnt=0,ans=0,cnt2=0;
    int c[n];
    memset(c,0,sizeof c);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    for(i=0;i<k;i++)
    {
        cin>>t;
        ans+=a[t-1]*(cnt-a[t-1]);
        cnt-=a[t-1];
        c[t-1]=1;
    }
    for(i=0;i<n-1;i++)
    {
        if(c[i]==0&&c[i+1]==0) ans+=a[i]*a[i+1];
    }
    if(c[0]==0&&c[n-1]==0) ans+=a[0]*a[n-1];
    cout<<ans<<endl;
    return 0;
}