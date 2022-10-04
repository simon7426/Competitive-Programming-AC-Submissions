#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int a,b,t,d,i,s=0;
    cin>>a>>b>>t>>d;
    for(i=1;i<=t;i++) {//cout<<i<<" "<<s<<" "<<a+(i-1)*d<<" "<<b+(t-i)*d<<endl;
            s+=min(a+(i-1)*d,b+(t-i)*d);}
    cout<<s<<endl;
    return 0;
}