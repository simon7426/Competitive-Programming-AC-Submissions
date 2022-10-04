#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    long long n,s;
    int c=0;
    cin>>n>>s;
    if(s%2==1)
    {
        cout<<1<<endl;
        return 0;
    }
    while(s%2==0&&s!=0)
    {
        s/=2;
        c++;
    }
    cout<<c+1<<endl;
    return 0;
}