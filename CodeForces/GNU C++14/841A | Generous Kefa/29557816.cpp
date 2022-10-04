#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
map<char,int> m;
 
main()
{
    int n,k,i,t;
    string s;
    cin>>n>>k;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        m[s[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second>k)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}