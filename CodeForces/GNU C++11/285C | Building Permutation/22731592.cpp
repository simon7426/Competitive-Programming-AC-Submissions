#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
typedef long long ll;
using namespace std;
main()
{
    int n;
    cin>>n;
    ll t;
    vector<ll> v2;
    int i,j;
    ll co=0;
    for(i=1;i<=n;i++)
        {
            cin>>t;
            v2.push_back(t);
        }
    sort(v2.begin(),v2.end());
    for(i=0;i<n;i++)
    {
        co+=abs(i+1-v2[i]);
    }
    cout<<co<<endl;
    return 0;
}