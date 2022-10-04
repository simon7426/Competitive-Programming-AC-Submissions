#include<iostream>
typedef long long int ll;
using namespace std;
ll happy(ll a)
{
    ll sum=0;
    if(a<=9)
        return a;
    while(a!=0)
    {
        sum+=((a%10)*(a%10));
        a/=10;
    }
    happy(sum);
}
main()
{
    ll t,n;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n;
        if(n==7)
            cout<<"Case #"<<i<<": "<<n<<" is a Happy number."<<endl;
        else if(happy(n)==1)
            cout<<"Case #"<<i<<": "<<n<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<i<<": "<<n<<" is an Unhappy number."<<endl;
    }
    return 0;
}

