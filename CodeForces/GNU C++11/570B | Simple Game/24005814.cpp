#include<iostream>
using namespace std;
main()
{
    int n,k;
    cin>>n>>k;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if((n-k)<k)
        cout<<k-1<<endl;
    else
        cout<<k+1<<endl;
    return 0;
}