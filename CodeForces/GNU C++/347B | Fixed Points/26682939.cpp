#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t;
    cin>>n;
    int a[n],cnt=0;
    for(i=0;i<n;i++)
    {cin>>a[i];
    if(a[i]==i) cnt++;}
    if(cnt==n)
    {
        cout<<n<<endl;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(i==a[a[i]]&&i!=a[i])
        {
            //cout<<i<<" "<<a[a[i]]<<endl;
            cout<<cnt+2<<endl;
            return 0;
        }
    }
    cout<<cnt+1<<endl;
    return 0;
}