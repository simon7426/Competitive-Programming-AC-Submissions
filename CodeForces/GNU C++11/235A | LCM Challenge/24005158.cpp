#include<iostream>
using namespace std;
main()
{
    long long int n;
    cin>>n;
    if(n<3)
        cout<<n<<endl;
    else if(n%2!=0)
        cout<<n*(n-1)*(n-2)<<endl;
    else
    {
        if(n%6==0)
            cout<<(n-3)*(n-1)*(n-2)<<endl;
        else
            cout<<n*(n-1)*(n-3)<<endl;
    }
}