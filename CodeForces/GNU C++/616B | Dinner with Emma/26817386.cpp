#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
using namespace std;
main()
{
    vector<int> a;
    int n,m,i,t,j,mi;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>t;
        mi=t;
        for(j=1;j<m;j++)
        {
            cin>>t;
            mi=min(mi,t);
        }
        a.push_back(mi);
    }
    sort(a.begin(),a.end());
    cout<<a[a.size()-1]<<endl;
    return 0;
}