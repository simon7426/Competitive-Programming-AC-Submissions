#include<iostream>
using namespace std;
main()
{
    int a,b,min;
    cin>>a>>b;
    (a>b)?min=b:min=a;
    if(min%2==0)
    {
        cout<<"Malvika"<<endl;
    }
    else
    {
        cout<<"Akshat"<<endl;
    }
}