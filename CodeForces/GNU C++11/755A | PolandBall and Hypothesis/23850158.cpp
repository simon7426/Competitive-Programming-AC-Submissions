#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n)
{
    int i;
    if(n%2==0)
        return false;
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<3<<endl;
        return 0;
    }
    if(n%2!=0)
        {cout<<1<<endl;return 0;}
    int i,p;
    for(i=1;i<=1000;i++)
    {
        p=n*i+1;
        if(prime(p)==false)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}