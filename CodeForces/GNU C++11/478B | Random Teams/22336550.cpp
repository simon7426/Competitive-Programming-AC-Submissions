#include<iostream>
using namespace std;
main()
{
    long long n,m,t,ma,mi,u,v;
    cin>>n>>m;
    t=n-(m-1);
    ma=0.5*t*(t-1);
    t=n%m;
    u=m-t;
    mi=0.5*((n/m)+1)*(n/m)*t+0.5*((n/m)-1)*(n/m)*u;
    cout<<mi<<" "<<ma<<endl;
    return 0;
}