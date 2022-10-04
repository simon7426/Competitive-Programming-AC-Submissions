#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
main()
{
    int n,a[100],i,max=0,tmp;
    cin>>n;
    cin>>a[0];
    for(i=1;i<n;i++)
    {
        cin>>a[i];
        tmp=a[i]-a[i-1];
        if(tmp>max)
            max=tmp;
    }
        set<int> s;
    set<int>::iterator it;
    for(i=2;i<n;i++)
    {
        tmp=a[i]-a[i-2];
        if(tmp>max)
            s.insert(tmp);
        else
            s.insert(max);
    }
    it=s.begin();
    cout<<*it<<endl;
    return 0;
}