#include<iostream>
using namespace std;
main()
{
    int n,m,a,i,ans,sum=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
    }
    if((n-1)*10+sum<=m)
    {
        ans=(m-sum)/5;
        cout<<ans<<endl;
    }
    else
        cout<<-1<<endl;
    return 0;
}