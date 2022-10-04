#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    long long n,m;
    cin>>n>>m;
    long long a[m],i;
    for(i=0;i<m;i++)
        cin>>a[i];
    sort(a,a+m);
    if(a[0]==1||a[m-1]==n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(i=2;i<m;i++)
    {
        if(a[i-1]+1==a[i]&&a[i-2]+2==a[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}