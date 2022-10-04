#include<iostream>
#include<cstdio>
using namespace std;
main()
{
    long long a,sum;
    while(scanf("%lld",&a)==1&&a!=0)
    {
        if(a<10)
            cout<<a<<endl;
        else if(a>9)
        {
            while(a>9)
            {
                sum=0;
                while(a>0){
                sum+=a%10;
                a/=10;
                }
                a=sum;
            }
            cout<<a<<endl;
        }

    }
    return 0;
}
