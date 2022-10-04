#include<iostream>
#include<cmath>
#include<algorithm>
typedef long long int ll;
using namespace std;
main()
{
    ll n,a,b,i,r,s=1e16,x,y,c,d;
    bool f=false;
    cin>>n>>a>>b;
    //cout<<s<<endl;
    r=6*n;
    if(r<a*b)
    {
        cout<<a*b<<endl;
        cout<<a<<" "<<b<<endl;
        return 0;
    }
    if(a>b){swap(a,b);f=true;}
    for(i=1;i<=r;i++)
    {
        x=i;
        y=(r+i-1)/i;
        if(y<x){break;}
        if(x<a)x=a;
        if(y<b)y=b;
        if(x*y<s){s=x*y,c=x,d=y;}
       // cout<<x<<" "<<y<<" "<<s<<endl;
    }
    cout<<s<<endl;
    if(f==true)
        swap(c,d);
    cout<<c<<" "<<d<<endl;
    return 0;
}