#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
    int n,i,t;
    map<int,int> a;
    set<int> b;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a[t]++;
        b.insert(t);
    }
    map<int,int>::iterator it;
    vector<int> v;
    for(it=a.begin();it!=a.end();it++)
    {
        v.push_back(it->second);
    }
    sort(v.begin(),v.end());
    cout<<v[v.size()-1]<<" "<<b.size()<<endl;
    return 0;
}
