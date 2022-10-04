#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long int ll;
using namespace std;
main()
{
    ll n,i,s;
    vector<ll> a;
    cin>>n;
    for(i=0;i<n;i++)
        {
            cin>>s;
            a.push_back(s);
        }
    sort(a.begin(),a.end());
    if(a[0]==a[n-1])
    {
        cout<<0<<" "<<((n-1)*n)/2<<endl;
        return 0;
    }
    ll mi=a[0],ma=a[n-1];
    ll cntm=1,cnt=1;
    for(i=1;i<n;i++)
    {
        if(mi==a[i])
            cnt++;
        else
            break;
    }
    for(i=n-2;i>=0;i--)
    {
        if(a[i]==ma)
            cntm++;
        else
            break;
    }
 
    cout<<a[n-1]-a[0]<<" "<<cnt*cntm<<endl;
    return 0;
}