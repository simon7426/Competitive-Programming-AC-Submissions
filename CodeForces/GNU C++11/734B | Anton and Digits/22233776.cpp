#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    long long a,b,c,d,e,ans;
    cin>>a>>b>>c>>d;
    e=min(min(a,c),d);
    ans=256*e;
    a=a-e;
    if(a<=0)
    {
        cout<<ans<<endl;
        return 0;
    }
    e=min(a,b);
    ans+=32*e;
    cout<<ans<<endl;
    return 0;
}