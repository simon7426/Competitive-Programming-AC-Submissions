#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    priority_queue<int> pq,pq2;
    int n,m,i,t;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>t;
        pq.push(t);
        pq2.push(-1*t);
    }
    int x,y,mi=0,ma=0;
    for(i=0;i<n;i++)
    {
        x=pq.top();
        y=pq2.top()*-1;
        pq.pop();
        pq2.pop();
        mi+=y;
        ma+=x;
        --x;--y;
        if(x!=0)pq.push(x);
        if(y!=0)pq2.push(y*(-1));
    }
    cout<<ma<<" "<<mi<<endl;
    return 0;
}