#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

main()
{
    long long int n;
    while(scanf("%lld",&n))
    {
        if(n<0)
            break;
        else
        {
            cout<<(long long)(n*n+n+2)/2<<endl;
        }
    }
    return 0;
}
