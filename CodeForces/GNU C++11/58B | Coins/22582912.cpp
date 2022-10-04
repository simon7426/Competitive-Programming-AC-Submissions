#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
main()
{
    int n,i,j,k;
    cin>>n;
    bool a[n+1];
    memset(a,true,sizeof a);
    for(i=2;i*i<=n;i++)
    {
        if(a[i]==true)
        for(j=i*2;j<=n;j+=i)
            a[j]=false;
    }
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    while(n!=1)
    {
        cout<<n<<" ";
        if(a[n]==true)
        {
            n=1;
            cout<<n<<endl;
            return 0;
        }
        else
        {
            for(k=2;k<=sqrt(n);k++)
            {
                if(n%k==0)
                {
                    n=n/k;
                    break;
                }
            }
        }
    }
}