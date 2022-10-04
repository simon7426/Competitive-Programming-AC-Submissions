#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
main()
{
    vector<string> a,b;
    int n,i;
    string s,h,t,u;
    cin>>n;
    cin>>h;
    for(i=0;i<n;i++)
    {
        t="";
        u="";
        cin>>s;
        t=s.substr(0,3);
        u=s.substr(5,7);
        //cout<<t<<" "<<u<<endl;
       // cout<<t<<" "<<u<<endl;
        if(t!=h)
            a.push_back(t);
        if(u!=h)
            b.push_back(u);
    }
    if(a.size()==b.size())
        cout<<"home"<<endl;
    else
        cout<<"contest"<<endl;
    return 0;
}