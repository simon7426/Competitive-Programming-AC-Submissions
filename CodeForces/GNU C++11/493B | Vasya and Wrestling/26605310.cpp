#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    vector<int> a,b;
    ll n,i,t,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        (t<0)?b.push_back(t):a.push_back(t);
        sum+=t;
    }
    if(sum<0) {cout<<"second"<<endl;return 0;}
    else if(sum>0) {cout<<"first"<<endl;return 0;}
    else if(sum==0)
    {
        int u=a.size();
        int v=b.size();
        int k=min(u,v);
        for(i=0;i<k;i++)
        {
            if(a[i]<abs(b[i]))
            {
                cout<<"second"<<endl;
                return 0;
            }
            else if(a[i]>abs(b[i]))
            {
                cout<<"first"<<endl;
                return 0;
            }
        }
    }
    cout<<((t<0)?"second":"first")<<endl;
    return 0;
}
 