#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
typedef long long int ll;
using namespace std;
main()
{
    ll t;
    int n,i;
    cin>>n;
    vector<ll>a;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
    }
    int m,x,y;
    pair<vector<ll>::iterator,vector<ll>::iterator> p;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>t;
        p=equal_range(a.begin(),a.end(),t);
        x=p.first-a.begin();
        y=p.second-a.begin();
        if(x<=0)
            cout<<"X"<<" ";
        else
            cout<<a[x-1]<<" ";
        if(y>=n)
            cout<<"X"<<endl;
        else
            cout<<a[y]<<endl;
    }
    return 0;
}
