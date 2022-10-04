#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t=0;
    string a,ans="";
    cin>>a;
    n=a.size();
    for(i=0;i<n;i++)
    {
        if(a[i]==a[i-1]&&a[i]==a[i-2])
            continue;
        if(t>2&&a[i]==ans[t-1]&&ans[t-2]==ans[t-3])
            continue;
        ans+=a[i];
        t++;
    }
    cout<<ans<<endl;
    return 0;
}