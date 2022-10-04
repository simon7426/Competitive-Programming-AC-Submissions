#include<iostream>
using namespace std;
main()
{
    long long int a,b,c,d,e,f;
    cin>>a>>b>>c;
 
    d=(a+b-c)/2;
    e=(b+c-a)/2;
    f=(a+c-b)/2;
    if(d>=0&&e>=0&&f>=0&&(a+b+c)%2==0)
        cout<<d<<" "<<e<<" "<<f<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}