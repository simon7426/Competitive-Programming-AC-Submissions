#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
main()
{
    string a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<max(a.size(),b.size())<<endl;
    return 0;
}