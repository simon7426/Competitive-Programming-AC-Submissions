#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int n;
    cin>>n;
    int s=sqrt(n);
    int i;
    for(i=s;i>0;i--)
    {
        if(n%i==0)
        {
            cout<<i<<" "<<n/i<<endl;
            return 0;
        }
    }
}