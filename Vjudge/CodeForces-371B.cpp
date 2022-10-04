#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
main()
{
    int n,m,i,p,q,k=0,sum=0;
    cin>>p>>q;
    n=max(p,q);
    m=min(p,q);
    for(i=2;i<=5;i++)
    {
        k=0;
        while(n%i==0)
        {
            n/=i;
            k++;
        }
        while(m%i==0)
        {
            m/=i;
            k--;
        }
        (k>=0)?sum+=k:sum+=-k;
    }
    (n==m)?cout<<sum<<endl:cout<<-1<<endl;
    return 0;
}
