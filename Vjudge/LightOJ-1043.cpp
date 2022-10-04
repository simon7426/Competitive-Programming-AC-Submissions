#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
main()
{
    int t;
    cin>>t;
    double a,b,c,d,e,f,g;
    int i;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b>>c>>d;
        e=d+1;
        f=sqrt(d/e);
        printf("Case %d: %.8f\n",i,a*f);
    }
    return 0;
}
