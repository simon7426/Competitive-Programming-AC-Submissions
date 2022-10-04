#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
using namespace std;
main()
{
    vector<int> a;
    int n,i,t,j,ma=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        ma=0;
        for(j=0;j<n;j++)
        {
            cin>>t;
            ma=max(ma,t);
        }
        a.push_back(ma);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==n-1) {a[i]=n;break;}
    }
    for(auto it:a)cout<<it<<" ";
            cout<<endl;
    return 0;
}