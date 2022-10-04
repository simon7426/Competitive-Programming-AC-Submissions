#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,k,i,s,t,cnt=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        cnt+=(t-s+1);
    }
    cout<<(k-(cnt%k))%k<<endl;
    return 0;
}