#include<iostream>
#include<vector>
typedef long long int ll;
using namespace std;
main()
{
    ios::sync_with_stdio(0);
    ll n,i,s=0,ss,t;
    cin>>n;
    vector<ll> sum(n,0),a;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
        s+=t;
    }
    if(s%3!=0)
    {
        cout<<0<<endl;return 0;
    }
    s/=3;
    ss=0;
    for(i=n-1;i>=0;i--)
    {
        ss+=a[i];
        if(ss==s)
            sum[i]=1;
    }
  //  for(auto it:sum)
  //      cout<<it<<" ";
  //  cout<<endl;
    for(i=n-2;i>=0;i--)
        sum[i]+=sum[i+1];
//    for(auto it:sum)
//        cout<<it<<" ";
//    cout<<endl;
    ss=0;
    t=0;
    for(i=0;i<n-2;i++)
    {
        ss+=a[i];
        if(ss==s)
            t+=sum[i+2];
    }
    cout<<t<<endl;
    return 0;
}