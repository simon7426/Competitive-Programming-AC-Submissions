#include<bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
queue<int> d,r;
main()
{
    optimize();
    string s;
    int n,i,t;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='D') d.push(i+1);
        else r.push(i+1);
    }
    while(!d.empty()&&!r.empty())
    {
        if(d.front()<r.front())
        {
            r.pop();
            t=n+d.front();
            d.pop();
            d.push(t);
        }
        else
        {
            d.pop();
            t=n+r.front();
            r.pop();
            r.push(t);
        }
    }
    cout<<((d.empty())?'R':'D')<<endl;
}