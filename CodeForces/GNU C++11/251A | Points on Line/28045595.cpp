#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
ll a[100100];
 
main()
{
    ll n,i,d,t,l=0,r=0,ans=0;
    cin>>n>>d;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(r<n)
    {
        if(a[r]-a[l]<=d)
        {
            t=r-l;
            ans+=max(0LL, (t*(t-1))/2);
            //5cout<<l<<" "<<r<<" "<<ans<<" "<<(t*(t-1))/2<<endl;
            r++;
        }
        else
        {
            //cout<<"here"<<endl;
            //r--;
            l++;
            //cout<<l<<" "<<r<<endl;
        }
    }
    cout<<ans<<endl;
}