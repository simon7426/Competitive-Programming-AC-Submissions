#include<iostream>
typedef long long int ll;
using namespace std;
main()
{
    ll i,n,k,mid,lo,hi,t,sum;
    cin>>n>>k;
    lo=1;hi=n;
    for(i=0;i<200;i++)
    {
        mid=lo+(hi-lo)/2;
        t=mid;
        sum=mid;
        while(t!=0)
        {
            sum+=t/k;
            t/=k;
        }
        if(sum==n){
            cout<<mid<<endl;
            return 0;
        }
        else if(sum>n)
            hi=mid;
        else
            lo=mid;
    }
    cout<<hi<<endl;
}