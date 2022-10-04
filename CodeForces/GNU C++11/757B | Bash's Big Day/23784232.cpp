#include<iostream>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
map<int,int> a;
void pf(int n)
{
    int i;
    if(n%2==0)
        a[2]++;
    while(n%2==0)
        n/=2;
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
            a[i]++;
        while(n%i==0)
            n/=i;
    }
    if(n!=1)
        a[n]++;
}
main()
{
    int n,i,j;
 
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>j;
        pf(j);
    }
    priority_queue<int> p;
    for(auto it=a.begin();it!=a.end();it++)
        p.push(it->second);
    if(p.empty())
    {
        cout<<1<<endl;
        return 0;
    }
    cout<<p.top()<<endl;
    return 0;
}