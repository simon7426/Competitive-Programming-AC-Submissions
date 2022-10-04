#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x,y;
    float e,f;
    e=(float)a/c;
    f=(float)b/d;
    if(e==f)
    {
        cout<<0<<"/"<<1<<endl;
    }
    else if(e<f)
    {
        x=__gcd(a,c);
        y=(a*c)/x;
        b*=(y/a);
        d*=(y/c);
        a=abs(b-d);
        c=max(b,d);
        x=__gcd(a,c);
        cout<<min(a/x,c/x)<<"/"<<max(c/x,a/x)<<endl;
    }
    else if (f<e)
    {
        x=__gcd(b,d);
        y=(b*d)/x;
        a*=(y/b);
        c*=(y/d);
        b=abs(a-c);
        d=max(c,a);
        x=__gcd(b,d);
        cout<<min(b/x,d/x)<<"/"<<max(b/x,d/x)<<endl;
    }
    return 0;
}