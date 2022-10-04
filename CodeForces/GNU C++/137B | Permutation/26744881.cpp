#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t;
    cin>>n;
    set<int> s;
    for(i=0;i<n;i++){
        cin>>t;
        if(t<=n&&t>=1)s.insert(t);}
    cout<<n-s.size()<<endl;
}