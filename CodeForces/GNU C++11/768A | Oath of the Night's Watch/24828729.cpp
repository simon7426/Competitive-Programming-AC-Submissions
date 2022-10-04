#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;
main()
{
    map<int,int> a;
    int n,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a[t]++;
    }
if(a.size()==1)
    {
        cout<<0<<endl;
        return 0;
    }
    auto it=a.begin();
    auto it1=a.rbegin();
    cout<<n-(it->second+it1->second)<<endl;
    return 0;
}