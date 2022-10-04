#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==1&&b!=1&&c!=1)
        cout<<(a+b)*c;
    else if(a!=1&&b==1&&c!=1)
    {
        if (a>c)
            cout<<(c+b)*a;
        else
            cout<<(a+b)*c;
    }
    else if(a!=1&&b!=1&&c==1)
        cout<<(c+b)*a;
    else if((a==c&&a==1&&b!=1))
        cout<<a+b+c;
    else if((a==b||b==c)&&b==1&&(a!=1||c!=1))
            a==1?cout<<2*c:cout<<2*a;
        else if(a==b==c==1)
            cout<<3;
    else
        cout<<a*b*c;
    return 0;
}