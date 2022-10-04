#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,j,t,cnt=0,ans=1e9;
    string a;
    cin>>n>>a;
    int dp[n],f[128];
    memset(f,0,sizeof f);
    for(i=0;i<n;i++)
    {
        if(f[a[i]]==0) {cnt++;f[a[i]]++;}
        else f[a[i]]++;
    }
    memset(f,0,sizeof f);
    int b=0,e=0,cur=0;
    for(i=0;i<n;i++)
    {
        if(cur<cnt)
        {
            for(j=e;j<n&&cur<cnt;j++)
            {
                if(!f[a[j]]) {cur++;}
                f[a[j]]++;e++;}
 
            if(cur==cnt) ans=min(e-b,ans);
        }
        else ans=min(ans,e-b);
        if(f[a[i]]==1) cur--;
        f[a[i]]--;
        b++;
    }
    cout<<ans<<endl;
    return 0;
}