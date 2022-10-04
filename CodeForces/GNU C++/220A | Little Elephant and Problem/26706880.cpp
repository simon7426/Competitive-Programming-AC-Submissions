#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,t;
    cin>>n;
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    t=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i]) t++;
    }
    if(t<=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}