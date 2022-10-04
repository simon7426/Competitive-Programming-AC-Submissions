#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
main()
{
    long long n,a,b,c,d,e;
    cin>>n>>a>>b>>c;
    if(n%4==0)
    {
        cout<<0<<endl;
    }
    else if(n%4==1)
    {
 
        d=a*3;
        e=b+a;
        cout<<min(d,min(e,c))<<endl;
    }
    else if(n%4==2)
    {
        d=2*a;
        e=2*c;
        cout<<min(d,min(b,e))<<endl;
    }
    else
    {
        d=c*3;
        e=b+c;
        cout<<min(a,min(e,d))<<endl;
    }
}