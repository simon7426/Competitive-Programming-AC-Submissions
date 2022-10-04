#include<iostream>
using namespace std;
main()
{
    long long n,l,i,c=0,f=0;
    cin>>n>>l;
    for(i=0;l!=1;i++)
    {
        if(l%n==0)
            l=l/n;
        else
        {
            f=1;
            break;
        }
    }
    (f==1)?cout<<"NO"<<endl:cout<<"YES\n"<<i-1<<endl;
    return 0;
}