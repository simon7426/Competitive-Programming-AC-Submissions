#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
typedef long long int ll;
main()
{
    priority_queue<int> q;
    int n,t,i,k,x;
    cin>>n;
    k=n;
    for(i=0;i<k;i++)
    {
        cin>>t;
        q.push(t);
        x=q.top();
        //cout<<x<<endl;
        while(n==x)
        {
            cout<<x<<" ";
            q.pop();
            n--;
            x=q.top();
        }
        cout<<endl;
    }
    return 0;
}