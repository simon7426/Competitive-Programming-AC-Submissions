#include<iostream>
#include<vector>
using namespace std;
main()
{
    vector<int> a,b,c;
    int n,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(t<0)
            a.push_back(t);
        else if(t>0)
            b.push_back(t);
        else
            c.push_back(t);
    }
    if(a.size()%2==0)
    {
        c.push_back(a[0]);
        a.erase(a.begin());
    }
    if(b.size()==0)
    {
        b.push_back(a[0]);
        b.push_back(a[1]);
        a.erase(a.begin());
        a.erase(a.begin());
    }
    cout<<a.size();
    for(i=0;i<a.size();i++)
        cout<<" "<<a[i];
    cout<<endl;
    cout<<b.size();
    for(i=0;i<b.size();i++)
        cout<<" "<<b[i];
    cout<<endl;
    cout<<c.size();
    for(i=0;i<c.size();i++)
        cout<<" "<<c[i];
    cout<<endl;
    return 0;
}