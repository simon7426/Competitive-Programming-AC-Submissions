#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
#include<iterator>
#include<set>
using namespace std;
//typedefs
typedef long long int ll;
main()
{
    ll n,k;
    cin>>n>>k;
    n%=6;
    switch(n)
    {
    case 1:{
        if(k==0)cout<<1<<endl;
        else if(k==1)cout<<0<<endl;
        else cout<<2<<endl;
        break;}
    case 2:{
        if(k==0)cout<<1<<endl;
        else if(k==1)cout<<2<<endl;
        else cout<<0<<endl;
        break;
    }
    case 3:
        {
        if(k==0)cout<<2<<endl;
        else if(k==1)cout<<1<<endl;
        else cout<<0<<endl;
        break;
        }
    case 4:
    {
        if(k==0)cout<<2<<endl;
        else if(k==1)cout<<0<<endl;
        else cout<<1<<endl;
        break;
    }
    case 5:
    {
        if(k==0)cout<<0<<endl;
        else if(k==1)cout<<2<<endl;
        else cout<<1<<endl;
        break;
    }
    default:
        cout<<k<<endl;
        break;
    }
    return 0;
}