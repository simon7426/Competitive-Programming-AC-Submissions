#include<iostream>
using namespace std;
main()
{
    long long int a;
    cin>>a;
    if(a==0)
    {
        cout<<"1"<<endl;
        return 0;
    }
    if(a%4==1)
        cout<<"8";
    else if(a%4==2)
        cout<<"4";
    else if(a%4==3)
        cout<<"2";
    else
        cout<<"6";
    cout<<endl;
    return 0;
}