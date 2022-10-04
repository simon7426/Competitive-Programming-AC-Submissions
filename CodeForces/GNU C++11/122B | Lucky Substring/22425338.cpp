#include<iostream>
#include<string>
using namespace std;
main()
{
    string a;
    int i,n4,n7;
    n4=n7=0;
    cin>>a;
    for(i=0;i<a.size();i++)
    {
        if(a[i]=='4')
            n4++;
        if(a[i]=='7')
            n7++;
    }
    if(n4==0&&n7==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n4>=n7)
        cout<<4<<endl;
    else
        cout<<7<<endl;
    return 0;
}