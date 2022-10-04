#include<iostream>
#include<algorithm>
using namespace std;
struct con
{
    int so;
    int pt;
};
bool com(con a,con b)
{
    if(a.so==b.so)
        return a.pt<b.pt;
    return a.so>b.so;
}
main()
{
    int n,po,c=1;
    cin>>n>>po;
    struct con a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].so>>a[i].pt;
    }
    sort(a,a+n,com);
    int i,j;
    for(i=po-1;i<n-1;i++)
    {
        if(a[i].so==a[i+1].so&&a[i].pt==a[i+1].pt)
            c++;
        else
            break;
    }
    for(i=po-2;i>=0;i--)
    {
        if(a[i].so==a[i+1].so&&a[i].pt==a[i+1].pt)
            c++;
        else
            break;
    }
    cout<<c<<endl;
    return 0;
}