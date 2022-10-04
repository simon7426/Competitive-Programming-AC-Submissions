#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,b,f=0;
    cin>>n>>b;
    int s,t,i,ma=0;
    vector<int> a;
    for(i=0;i<n;i++)
    {
        cin>>s;
        a.push_back(s);
        ma=max(ma,s);
    }
    n-=(2*b-n);
    //<<n;
    for(i=0;i<n;i++)
    {
        ma=max(ma,a[i]+a[n-i-1]);
        //f+=2;
    }
    cout<<ma<<endl;
    return 0;
}