#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
main()
{
    ll n,i,j;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-2;i++)
    {
        if(a[i]+a[i+1]>a[i+2])
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}