#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,d,i,j,t=0;
    cin>>n>>d;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        t+=a[i];
    }
    if((n-1)*10+t>d) {cout<<-1<<endl;return 0;}
    cout<<(d-t)/5<<endl;
    return 0;
}
