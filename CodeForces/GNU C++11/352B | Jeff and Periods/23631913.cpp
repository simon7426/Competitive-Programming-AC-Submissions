#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
main()
{
    int n,i,t,j,f,k;
    cin>>n;
    map<int,vector<int> > a;
    set<int> s;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a[t].push_back(i);
        s.insert(t);
    }
    set<int>::iterator it;
    vector<pair<int,int> > v;
    for(it=s.begin();it!=s.end();it++)
    {
        if(a[*it].size()==1)
            v.push_back(make_pair(*it,0));
        else
        {
            f=0;
            k=a[*it][1]-a[*it][0];
           // cout<<k<<endl;
            for(j=1;j<a[*it].size()-1;j++)
            {
              if(a[*it][j+1]-a[*it][j]!=k)
              {
                  f=1;
                  break;
              }
            }
            if(f==0)
                v.push_back(make_pair(*it,k));
        }
    }
    cout<<v.size()<<endl;
    for(i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    return 0;
}