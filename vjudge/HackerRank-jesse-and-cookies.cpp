#include<iostream>
#include<queue>
typedef long long int ll;
using namespace std;
int main()
{
    ll n,i,k,t,cnt;
    priority_queue<ll> a;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a.push(t*-1);
    }
    if(n==1||a.top()*-1>=k) {cout<<0<<endl;return 0;}
    i=0;
    while(a.size()>1)
    {
        cnt=(a.top()*-1);
        a.pop();
        cnt+=(-2*a.top());
        a.pop();
        i++;
        a.push(cnt*-1);
        if((a.top()*-1)>=k)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
