#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    long long n,i,c=0,x,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        x=t;
        cin>>t;
        if(i>=1&&t<x)
        {
            c+=x-t;
        }
    }
    cout<<c<<endl;
    return 0;
}