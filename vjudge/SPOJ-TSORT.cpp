#include<iostream>
#include<queue>
using namespace std;
main()
{
    int n,i,t;
    priority_queue<int> a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a.push(t*-1);
    }
    for(i=0;i<n;i++)
    {
        cout<<a.top()*-1<<endl;
        a.pop();
    }
    return 0;
}
