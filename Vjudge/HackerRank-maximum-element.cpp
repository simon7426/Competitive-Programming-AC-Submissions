#include<iostream>
#include<algorithm>
#include<stack>
#include<utility>
#include<cstdio>
typedef long long int ll;
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,i,j,ma=0,s,t;
    cin>>n;
    stack<pair<ll,ll> > a;
    for(i=0;i<n;i++)
    {
        cin>>s;
        //cout<<ma<<" ";
        if(s==1)
        {
            cin>>t;
            ma=max(ma,t);
            a.push(make_pair(t,ma));
        }
        else if(s==2)
        {
            a.pop();
            if(a.size()==0)
                ma=0;
            else
                ma=a.top().second;

        }
        else
            {
                if(a.size()==0)
                    cout<<0<<endl;
                else
                    cout<<a.top().second<<endl;
            }
    }
    return 0;
}
