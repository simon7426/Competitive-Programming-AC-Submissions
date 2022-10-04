#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,v0,v1,a,l;
    cin>>n>>v0>>v1>>a>>l;
    int c=v0,cnt=1;
    while(c<n)
    {
        c-=l;
        c+=min(v0+cnt*a,v1);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}