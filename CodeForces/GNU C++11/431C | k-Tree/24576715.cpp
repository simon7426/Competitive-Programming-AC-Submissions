#include<iostream>
#include<algorithm>
typedef long long int ll;
#define mod 1000000007
using namespace std;
void fun(ll &a,ll b)
{
    if(a+b>mod)
        a=a+b-mod;
    else
        a=a+b;
}
main()
{
    ll a[101][2];
    ll n,k,d,i,j;
    cin>>n>>k>>d;
    a[0][0]=1;
    a[0][1]=0;
    for(i=1;i<=n;i++)
    {
        a[i][0]=a[i][1]=0;
        for(j=1;j<=k;j++)
        {
            if(i-j<0)break;
            if(j<d)
            {
                fun(a[i][0],a[i-j][0]);
                fun(a[i][1],a[i-j][1]);
            }
            else
            {
                fun(a[i][1],a[i-j][0]);
                fun(a[i][1],a[i-j][1]);
            }
        }
    }
//    for(i=0;i<=n;i++)
//        cout<<a[i][0]<<" "<<a[i][1]<<endl;
cout<<a[n][1]<<endl;
    return 0;
}