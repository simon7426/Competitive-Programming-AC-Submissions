#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
main()
{
    int n,m,t;
    cin>>n>>m;
    if(n==2)
    {
        if(m!=1)
            cout<<5<<endl;
        else
            cout<<4<<endl;
    }
    else if(n==1||n==3||n==5||n==7||n==8||n==10||n==12)
    {
        if(m>5)
            cout<<6<<endl;
        else
            cout<<5<<endl;
    }
    else
    {
        if(m>=7)
            cout<<6<<endl;
        else
            cout<<5<<endl;
    }
    return 0;
}