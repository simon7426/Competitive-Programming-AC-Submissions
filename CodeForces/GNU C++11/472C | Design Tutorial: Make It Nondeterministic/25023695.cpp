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
    string s,t;
    vector<string> v,vs;
    int n,i,a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        v.push_back(min(s,t));
        vs.push_back(max(s,t));
    }
    /*
    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" "<<vs[i]<<endl;
    }*/
    cin>>a;
    a-=1;
    s=min(v[a],vs[a]);
    for(i=1;i<n;i++)
    {
        cin>>a;
        a-=1;
        if( s < v[a] ) s=v[a];
 
        else if(s < vs[a]) s=vs[a];
 
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}