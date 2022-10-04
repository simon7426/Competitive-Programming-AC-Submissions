#include<iostream>
#include<vector>
#include<utility>
using namespace std;
main()
{
    vector<int> a,t;
    pair<int,int>b[101];
    a.assign(105,0);
    int n,m,r,s,i,j,sum=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>r;
        a[i]=r;
    }
    for(i=0;i<m;i++)
    {
        cin>>s>>r;
        b[i]=make_pair(s,r);
    }
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=b[i].first;j<=b[i].second;j++)
        {
            sum+=a[j];
        }
        if(sum>0)
        {
            t.push_back(sum);
        }
    }
    sum=0;
    if(t.empty())
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<t.size();i++)
        sum+=t[i];
    cout<<sum<<endl;
    return 0;
}