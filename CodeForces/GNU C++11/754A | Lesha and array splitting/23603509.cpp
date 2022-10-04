#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool com(const pair<int,int> i,const pair<int,int> j)
{
    return i.first<j.first;
}
main()
{
    int n,i,t,cnt=0,s;
    cin>>n;
    vector<int> a;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(t==0)
            cnt++;
        a.push_back(t);
    }
    if(cnt==n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<pair <int,int> > p;
    s=n;
    while(a[n-1]==0)
        n--;
    for(i=0;i<n;i++)
    {
 
        if(a[i]!=0)
            {
                t=i;
                if(i==n-1)
                    i=s-1;
                p.push_back(make_pair(t+1,i+1));}
        else
        {
            t=i+1;
            while(a[i]==0&&i<n-1)
                i++;
            if(i==n-1)
                i=s-1;
            p.push_back(make_pair(t,i+1));
        }
    }
    cout<<"YES"<<endl;
    cout<<p.size()<<endl;
    sort(p.begin(),p.end(),com);
    for(i=0;i<p.size();i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    return 0;
}