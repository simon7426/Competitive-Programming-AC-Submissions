#include<iostream>
#include<algorithm>
typedef unsigned long long int ll;
using namespace std;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
main()
{
    ll a,b,x,y,ab,cd,c,d,e,f;
    cin>>a>>b>>x>>y;
    e=gcd(x,y);
    x/=e;
    y/=e;
    ab=a*b;
    if(b<y||a<x)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    c=a/x;
    d=b/y;
    ab=c*x*c*y;
    cd=d*x*d*y;
    //cout<<ab<<" "<<cd<<endl;
    if(ab<cd)
        cout<<c*x<<" "<<c*y<<endl;
    else
        cout<<d*x<<" "<<d*y<<endl;
    return 0;
}