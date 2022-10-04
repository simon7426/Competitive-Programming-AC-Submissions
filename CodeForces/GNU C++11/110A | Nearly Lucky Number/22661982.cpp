#include<iostream>
typedef long long ll;
using namespace std;
main()
{
    ll a,t;
    int c=0;
    cin>>a;
    while(a>0)
    {
        t=a%10;
        if(t==4||t==7)
            c++;
        a/=10;
    }
    (c==7||c==4)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}