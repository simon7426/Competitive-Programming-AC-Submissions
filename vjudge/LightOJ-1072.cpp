#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
main()
{
    int t,i;

    cin>>t;
    double n,r,rr,pi,a,q;
    pi=acos(-1);
    //cout<<pi<<endl;
    for(i=1;i<=t;i++)
    {
        cin>>rr>>n;
        a=pi/n;
        //cout<<a<<endl;
        q=sin(a);
        //cout<<q<<endl;
        r=(q*rr)/(q+1);
        printf("Case %d: %.8f\n",i,r);
    }
    return 0;
}
