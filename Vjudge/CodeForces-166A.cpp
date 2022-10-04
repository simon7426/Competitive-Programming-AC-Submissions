#include<iostream>
#include<algorithm>
using namespace std;
struct con
{
    int po;
    int pt;
};
bool com(con a,con b)
{
    if(a.po==b.po)
        return a.pt<b.pt;
    return a.po>b.po;
}
main()
{
    int n,k,c=0;
    cin>>n>>k;
    struct con a[n];
    int i,s,t;
    for(i=0;i<n;i++)
    {
        cin>>a[i].po;
        cin>>a[i].pt;
    }
    sort(a,a+n,com);
    for(i=k-1;i>0;i--)
    {
        if(a[i].po==a[i-1].po&&a[i].pt==a[i-1].pt)
            c++;
        else
            break;
    }
    for(i=k-1;i<n-1;i++)
    {
        if(a[i].po==a[i+1].po&&a[i].pt==a[i+1].pt)
            c++;
        else
            break;
    }
    cout<<c+1<<endl;
    return 0;
}
