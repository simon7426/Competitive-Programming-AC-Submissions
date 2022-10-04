#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct pos
{
    int p;
    int v;
}st[1000];
bool comp(pos a,pos b)
{
    return a.v>b.v;
}
main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k,n,i;
    cin>>n>>k;
    int a[k];
    for(i=0;i<n;i++)
    {
        cin>>st[i].v;
        st[i].p=i+1;
    }
    sort(st,st+n,comp);
    cout<<st[k-1].v<<endl;
    for(i=0;i<k;i++)
    {
        a[i]=st[i].p;
    }
    sort(a,a+k);
    for(i=0;i<k;i++)
        cout<<a[i]<<" ";
    return 0;
}