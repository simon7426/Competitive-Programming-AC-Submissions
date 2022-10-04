#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=1;
    for(i=0;i<n;i++)
    {
        if(a[i]<(i/ans)) ans++;
    }
    cout<<ans<<endl;
}