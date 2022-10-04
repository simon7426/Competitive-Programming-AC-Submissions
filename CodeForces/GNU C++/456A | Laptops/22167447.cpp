#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
main()
{
    int n,i,p,q;
    cin>>n;
    pair<int,int> a[n];
    for(i=0;i<n;i++)
    {
        cin>>p>>q;
        a[i]=make_pair(p,q);
    }
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        if(a[i].second>a[i+1].second)
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }
    cout<<"Poor Alex"<<endl;
    return 0;
}