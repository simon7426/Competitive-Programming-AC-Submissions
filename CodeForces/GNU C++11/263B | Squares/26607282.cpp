#include<bits/stdc++.h>
using namespace std;
bool com(const int a,const int b)
{
    return a>b;
}
 
typedef long long ll;
main()
{
    vector<int> a;
    int n,i,t,k;
    cin>>n>>k;
    if(n<k) {cout<<-1<<endl;return 0;}
    for(i=0;i<n;i++)
    {
        cin>>t;
        a.emplace_back(t);
    }
    sort(a.begin(),a.end(),com);
   // for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<a[k-1]<<" "<<0<<endl;
    return 0;
}