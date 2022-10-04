#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,k,ma=0,mi=0,x;
    int i,j;
    cin>>n>>k;
    int a[n];
    cin>>a[0];
    ma=a[0];
    mi=a[0];
    for(i=1;i<n;i++)
    {
        cin>>a[i];
        ma=max(a[i],ma);
        mi=min(a[i],mi);
    }
    if(ma-mi>k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(i=0;i<n;i++)
    {
        x=1;
        for(j=0;j<a[i];j++)
        {
            cout<<x++<<" ";
            if(x>k) x=1;
        }
        cout<<endl;
    }
    return 0;
}