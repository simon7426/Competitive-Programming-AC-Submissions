#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int n,i,j;
main()
{
    cin>>n;
    int a[n],pr[n],po[n],ma,ans;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==2){cout<<2<<endl;return 0;}
    pr[0]=1;
    for(i=1;i<n;i++)
    {
        if(a[i]>a[i-1]) pr[i]=pr[i-1]+1;
        else pr[i]=1;
    }
    po[n-1]=1;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1]) po[i]=po[i+1]+1;
        else po[i]=1;
    }
    ans=max(pr[0],po[n-1]);
    for(i=1;i<n-1;i++)
    {
        if(a[i+1]-a[i-1]>1) ans=max(ans,po[i+1]+pr[i-1]+1);
        ans=max(ans,pr[i]+1);
        ans=max(po[i]+1,ans);
    }
    cout<<ans<<endl;
    return 0;
}