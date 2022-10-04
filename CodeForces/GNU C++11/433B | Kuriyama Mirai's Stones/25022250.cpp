#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
#include<iterator>
#include<set>
using namespace std;
typedef long long int ll;
main()
{
    vector<ll> a,b;
    ll m,n,i,j,t,l,r;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        b.push_back(t);
    }
    a=b;
    sort(a.begin(),a.end());
    for(i=1;i<n;i++)
    {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>t>>l>>r;
        if(t==1)
        {
            if(l!=1)
            cout<<b[r-1]-b[l-2]<<endl;
            else
                cout<<b[r-1]<<endl;
        }
        else
        {
            if(l!=1)
            cout<<a[r-1]-a[l-2]<<endl;
            else
                cout<<a[r-1]<<endl;
        }
    }
    return 0;
}