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
    int a[200100],b[200100];
    vector<pair<int,int> > v;
    int n,i,t,cnt=0,di=0,k;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
    {
        if(a[i]<=b[i])
        {cnt+=a[i];di++;}
        else
            {cnt+=b[i];v.push_back(make_pair(a[i]-b[i],i));}
    }
    if(di>=k){
        cout<<cnt<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    for(i=0;i<k-di;i++)
    {
        cnt+=v[i].first;
    }
    cout<<cnt<<endl;
}