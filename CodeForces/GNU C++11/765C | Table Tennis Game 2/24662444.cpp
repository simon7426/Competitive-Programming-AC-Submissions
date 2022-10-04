#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
main()
{
    ll k,a,b,t,u,v,m,n;
    cin>>k>>a>>b;
    m=a/k;
    n=b/k;
    t=m+n;
    u=a%k;
    v=b%k;
    if(m==0&&v!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n==0&&u!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<t<<endl;
    return 0;
}