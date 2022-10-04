#include<iostream>
using namespace std;
main()
{
    long long i,j=0,a=0,b;
    cin>>i;
    while(a!=1)
    {
        i++;
        j++;
        b=i;
        if(b<0)
            b*=-1;
        while(b!=0)
        {
            if(b%10==8)
            {
                a=1;
                break;
            }
            b/=10;
        }
    }
    cout<<j<<endl;
    return 0;
}