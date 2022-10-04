#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
main()
{
    int a,b;
    cin>>a>>b;
    if(a==0&&b==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(abs(a-b)<=1)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
}