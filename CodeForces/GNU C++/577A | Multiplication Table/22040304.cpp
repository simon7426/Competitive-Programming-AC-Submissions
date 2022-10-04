#include<iostream>
using namespace std;
main()
{
    long long a,b,i,count;
    cin>>a>>b;
    a>=b?count=1:count=0;
    for(i=2;i<=a;i++)
    {
        if (b%i==0&&b/i<=a)
            count++;
    }
    cout<<count<<endl;
    return 0;
}