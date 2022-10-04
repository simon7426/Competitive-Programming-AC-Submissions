#include<iostream>
using namespace std;
main()
{
    long long n,m,i,a,b,t;
    cin>>n>>m;
    cin>>a;
    t=a-1;
    for(i=1;i<m;i++)
    {
        cin>>b;
        if(b>a)
            t+=b-a;
        else if(b<a)
            t+=(n+b)-a;
        a=b;
    }
    cout<<t<<endl;
}