#include<iostream>
#include<cstring>
using namespace std;
main()
{
    int a[1000];
    memset(a,0,sizeof a);
    int n,m,tmp,i;
    cin>>n>>m;
    for(i=0;i<2*m;i++)
    {
        cin>>tmp;
        a[tmp]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            tmp=i;
            break;
        }
    }
    cout<<n-1<<endl;
    for(i=1;i<=n;i++)
    {
        if(i!=tmp)
            cout<<tmp<<" "<<i<<endl;
    }
    return 0;
}