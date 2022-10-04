#include<bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
map<ll,ll> m;
stack<ll> s1,s2;
main()
{
    optimize();
    ll n,t,u,v,w,x,y,z,ans=0;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>u>>v>>w;
        }
        else
        {
            cin>>u>>v;
        }
        while(u!=0)
        {
            s1.push(u%2);
            u>>=1LL;
        }
        while(v!=0)
        {
            s2.push(v%2);
            v>>=1LL;
        }
        //cout<<u<<" "<<v<<" "<<s1.size()<<" "<<s2.size()<<endl;
        s1.pop();
        s2.pop();
       // cout<<u<<" "<<v<<" "<<s1.size()<<" "<<s2.size()<<endl;
        x=1;
        ans=0;
        if(!s1.empty()&&!s2.empty())
        {
        while(s1.top()==s2.top())
        {
            if(s1.top()==0)
                x=x<<1;
            else
                x=(x<<1)+1;
            s1.pop();
            s2.pop();
            if(s1.empty()||s2.empty()) break;
        }
        }
        y=x;
        z=x;
        //cout<<x<<" "<<y<<" "<<z<<endl;
        if(t==1)
        {
            while(!s1.empty())
            {
                if(s1.top()==0)
                    y<<=1;
                else
                    y=(y<<1)+1;
                m[y]+=w;
                s1.pop();
            }
            while(!s2.empty())
            {
                if(s2.top()==0)
                    z<<=1;
                else
                    z=(z<<1)+1;
                m[z]+=w;
                s2.pop();
            }
        }
        else
        {
            while(!s1.empty())
            {
                if(s1.top()==0)
                    y<<=1;
                else
                    y=(y<<1)+1;
                ans+=m[y];
                s1.pop();
            }
            while(!s2.empty())
            {
                if(s2.top()==0)
                    z<<=1;
                else
                    z=(z<<1)+1;
                ans+=m[z];
                s2.pop();
            }
            cout<<ans<<endl;
        }
    }
}