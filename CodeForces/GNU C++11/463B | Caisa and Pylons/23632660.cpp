#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,d=0,p,q=0,i,h=0,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        p=t;
        h+=q-p;
        //cout<<h<<endl;
        if(h<0)
            {d+=-h;h=0;}
        q=p;
    }
    cout<<d<<endl;
}