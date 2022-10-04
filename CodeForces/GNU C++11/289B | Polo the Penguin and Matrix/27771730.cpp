#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,d,i,t,b[10010];
    cin>>n>>m>>d;
    n*=m;
    cin>>b[0];
    m=b[0]%d;
    for(i=1;i<n;i++)
    {
        cin>>b[i];
        if(b[i]%d!=m)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    sort(b,b+n);
    int ans=0;
    t=b[n/2];
    for(i=0;i<n;i++)
    {
        ans+=abs(t-b[i])/d;
    }
    cout<<ans<<endl;
    return 0;
}