#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long sumd(long long i)
{
    if(i==0)
        return 0;
    return i%10+sumd(i/10);
}
main()
{
    long long n,i,b;
    cin>>n;
    b=max((long long)sqrt(n)-100,1LL);
    for(i=b;i<sqrt(n);i++)
    {
        if(i*i+sumd(i)*i==n)
        {cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}