#include<iostream>
#include<string>
#include<algorithm>
typedef long long int ll;
using namespace std;
main()
{
    ll n,m,t,i;
    cin>>n>>m;
    if(n*2+2<m||n-1>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n>=m){
        if(n>m){cout<<0;n--;}}
    t=m-n;
    for(i=0;i<min(n,t);i++)
        cout<<110;
    m-=2*min(t,n);
    n-=min(t,n);
    for(i=0;i<min(n,m)&&n!=0;i++)
            cout<<10;
    m-=min(n,m);
    n-=min(n,m);
    if(m!=0)for(i=0;i<m;i++)cout<<1;
    cout<<endl;return 0;
    //cout<<m<<" "<<n<<" "<<t<<endl;
}