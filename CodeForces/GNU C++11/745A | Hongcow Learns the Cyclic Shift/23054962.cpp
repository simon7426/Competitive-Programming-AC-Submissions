#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
main()
{
    string a,s,t;
    cin>>a;
    s=a;
    int n,i,j;
    n=a.size();
    for(i=0;i<a.size();i++)
    {
        t+=s[n-1];
        for(j=0;j<n-1;j++)
            t+=s[j];
        //cout<<t<<endl;
        if(t==a)
            break;
        s=t;
        t="";
    }
    cout<<i+1<<endl;
    return 0;
}