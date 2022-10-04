#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int a,b,c,x,y,z,sum=0;
    cin>>a>>b>>c;
    x=sqrt((a*c)/b);
    y=sqrt((a*b)/c);
    z=sqrt((b*c)/a);
    cout<<(x+y+z)*4<<endl;
    return 0;
}
 