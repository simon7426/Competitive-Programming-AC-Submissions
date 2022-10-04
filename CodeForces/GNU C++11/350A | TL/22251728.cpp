#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,m,v;
    cin>>n>>m;
    int a[n],b[m];
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    if(a[0]*2<=a[n-1])
        v=a[n-1];
    else
        v=2*a[0];
    if(v<b[0])
        cout<<v<<endl;
    else
        cout<<-1<<endl;
    return 0;
}