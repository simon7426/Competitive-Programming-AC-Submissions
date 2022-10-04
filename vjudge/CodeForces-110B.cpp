#include<iostream>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(i%4==1)
            cout<<'a';
        else if(i%4==2)
            cout<<'b';
        else if(i%4==3)
            cout<<'c';
        else if(i%4==0)
            cout<<'d';
    }
}
