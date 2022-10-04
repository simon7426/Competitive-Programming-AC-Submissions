#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
main()
{
    //freopen("input.txt","r",stdin);
    string a;
    int i,k,al[26],sum=0,max,n;
    cin>>a;
    cin>>k;
    cin>>al[0];
    max=al[0];
    for(i=1;i<26;i++)
    {
        cin>>al[i];
        if(al[i]>max)
            max=al[i];
    }
    n=a.size();
    for(i=0;i<n;i++)
        sum+=al[(a[i]-97)]*(i+1);
    for(i=n;i<n+k;i++)
        sum+=(i+1)*max;
    cout<<sum<<endl;
    return 0;
}