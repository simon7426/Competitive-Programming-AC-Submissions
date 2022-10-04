#include<iostream>
typedef long long int ll;
using namespace std;
main()
{
    ll n,i,cnt=1;
    cin>>n;
    ll x[n],h[n];
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>h[i];
    }
    for(i=1;i<n-1;i++)
    {
        if(x[i]-h[i]>x[i-1])
        {
            cnt++;
        }
        else if(x[i]+h[i]<x[i+1])
        {
            cnt++;
            x[i]=x[i]+h[i];
        }
    }
    cout<<cnt+(n>1)<<endl;
    return 0;
}