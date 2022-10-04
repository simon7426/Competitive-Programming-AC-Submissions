#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int n;
    cin>>n;
    int i;
    if(n%2==0)
    {
        cout<<n/2<<endl;
        for(i=0;i<n;i+=2)
            cout<<2<<" ";
        cout<<endl;
    }
    else
    {
        cout<<(n-3)/2+1<<endl;
        for(i=0;i<n-3;i+=2)
            cout<<2<<" ";
        cout<<3<<endl;
    }
    return 0;
}