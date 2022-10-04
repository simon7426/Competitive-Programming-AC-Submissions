#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,x,d,i,l=0,r=0,t,f=1;
    string s;
    cin>>n>>d;
    cin>>s;
    d--;
    x=n/2;
    int cnt[x];
    if(d>=x) d=n-d-1;
    for(i=0;i<x;i++)
    {
        t=abs(s[i]-s[n-1-i]);
        cnt[i]=min(t,26-t);
        if(cnt[i]!=0)
        {
            if(f==1)
            {
                l=i;
                f=0;
            }
            r=i;
        }
    }
    int ans=0;
    for(i=0;i<x;i++)ans+=cnt[i];
    if(ans==0) l=r=d;
    ans+=min(abs(d-l),abs(d-r))+r-l;
    cout<<ans<<endl;
    return 0;
}