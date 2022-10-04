#include<iostream>
using namespace std;
main()
{
    long long r,l,i,a,b,c;
    cin>>l>>r;
    if(r-l<2)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    if(l%2==0)
        cout<<l<<" "<<l+1<<" "<<l+2;
    else
    {
        if(r-l<3)
            cout<<"-1"<<endl;
        else
            cout<<l+1<<" "<<l+2<<" "<<l+3;
    }
    return 0;
}