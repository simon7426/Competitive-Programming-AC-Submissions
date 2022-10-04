#include<iostream>
using namespace std;
main()
{
    int n,a,b,c,i;
    int d;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        d=c%a;
        d+=b;
        if(d>a)
            d-=a;
        cout<<"Case "<<i<<": "<<d<<endl;
    }
    return 0;
}
