#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long int ll;
main()
{
    string s;
    cin>>s;
    ll a,b;
    cin>>a>>b;
    int si=s.size();
    int x[si],y[si];
    memset(x,0,sizeof x);
    memset(y,0,sizeof y);
    ll t=0,i;
    for(i=0;i<si;i++)
    {
        t=(t+(s[i]-'0'))%a;
       // cout<<t<<endl;
        if(t==0) x[i]=1;
        t=(t*10)%a;
    }
    ll r=1;
    t=0;
    for(i=si-1;i;i--)
    {
        t=(((s[i]-'0')*r)+t)%b;
        r=(r*10)%b;
        //cout<<t<<endl;
        if(t==0)y[i]=1;
    }
    for(i=0;i<si;i++)
    {
        if(x[i]==1&&y[i+1]==1&&s[i+1]!='0')
        {
            cout<<"YES"<<endl;
            cout<<s.substr(0,i+1)<<"\n";
            cout<<s.substr(i+1,si)<<"\n";
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}