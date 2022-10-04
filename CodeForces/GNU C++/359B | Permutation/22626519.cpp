#include<iostream>
using namespace std;
main()
{
    int n,k,c=0;
    cin>>n>>k;
    for(int i=1;i<=2*n;i+=2)
    {
        if(c<k)
            cout<<i+1<<" "<<i<<" ";
        else
            cout<<i<<" "<<i+1<<" ";
        c++;
    }
    return 0;
}