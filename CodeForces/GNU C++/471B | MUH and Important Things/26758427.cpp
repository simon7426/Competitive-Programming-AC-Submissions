#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    vector< pair<int,int> > x,y,z;
    int n,i,u;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>u;
        x.push_back(make_pair(u,i+1));
    }
    pair<int,int> t;
    sort(x.begin(),x.end());
    y=x,z=x;
    int cnt=0;
    for(i=0;i<n-1;i++)
    {
        if(x[i].first==x[i+1].first)
        {
            cnt++;
            if(cnt==1)
            {
                t=y[i];
                y[i]=y[i+1];
                y[i+1]=t;
            }
            else if(cnt==2)
            {
                t=z[i];
                z[i]=z[i+1];
                z[i+1]=t;
            }
        }
    }
    if(cnt<2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(i=0;i<n;i++)
        cout<<x[i].second<<" ";
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<y[i].second<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<z[i].second<<" ";
    }
    cout<<endl;
}