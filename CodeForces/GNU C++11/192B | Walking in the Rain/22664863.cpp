#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
    int n,m1,m2,m,t,i,mt;
    vector<int> v;
    cin>>n;
    cin>>m1;
    if(n==1)
    {
        cout<<m1;
        return 0;
    }
    cin>>mt;
    for(i=2;i<n-1;i++)
        {
           cin>>t;
           v.push_back(max(mt,t));
           mt=t;
        }
    if(n>2){
    cin>>m2;
    m=min(m1,m2);}
    else
        m=min(m1,mt);
    if(v.empty()==false){
        sort(v.begin(),v.end());
        m=min(m,v[0]);}
    cout<<m<<endl;
    return 0;
}