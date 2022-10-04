#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
struct fri
{
    ll mo;
    ll ff;
};
bool com(fri a,fri b)
{
    return a.mo<b.mo;
}
main()
{
    ll j=0,i,n,d,ma=0,sum=0;
    cin>>n>>d;
    struct fri a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i].mo>>a[i].ff;
    }
    sort(a,a+n,com);
    for(i=0;i<n;i++)
    {
       sum+=a[i].ff;
       while(a[i].mo-a[j].mo>=d)
            sum-=a[j++].ff;
       ma=max(ma,sum);
    }
    cout<<ma<<endl;
    return 0;
}