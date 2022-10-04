#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,i,j;
    int x[55],y[55],z[55],cnt[55];
    cin>>n;
    x[0]=0;
    for(i=1;i<=n-1;i++)
        cin>>x[i];
    for(i=0;i<n-1;i++)
        cin>>y[i];
    y[n-1]=0;
    for(i=0;i<n;i++)
        cin>>z[i];
    for(i=1;i<=n-1;i++)
        x[i]+=x[i-1];
    for(i=n-2;i>=0;i--)
        y[i]+=y[i+1];
    for(i=0;i<n;i++)
        cnt[i]=x[i]+y[i]+z[i];
    sort(cnt,cnt+n);
    cout<<cnt[1]+cnt[0]<<endl;
}