#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t,cnt=0;
    set<int> s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>t;
        if(t!=i) s.insert(t);
        else cnt++;
    }
    cout<<cnt+s.size()/2<<endl;
}