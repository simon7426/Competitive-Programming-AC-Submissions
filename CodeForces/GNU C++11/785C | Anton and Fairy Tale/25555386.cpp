#include<iostream>
#include<cmath>
typedef long long int ll;
using namespace std;
main()
{
    ll n,m,k,sum;
    cin>>n>>m;
    if(n<=m)
    {
        cout<<n<<endl;
        return 0;
    }
    sum=m;
    n-=m;
    n*=2;
    k=sqrt(n);
    n/=2;
    while((k*(k+1)/2)>n)
    {
        k--;
    }
    while((k*(k+1)/2)<n)
    {
        k++;
    }
    cout<<sum+k<<endl;
    return 0;
}