#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
main()
{
    int n,i;
    ll t;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int cnt=1;
    t=a[0];
    for(i=1;i<n;i++)
    {
        if(t>a[i])
            continue;
        cnt++;
        t+=a[i];
    }
    cout<<cnt<<endl;
    return 0;
}
