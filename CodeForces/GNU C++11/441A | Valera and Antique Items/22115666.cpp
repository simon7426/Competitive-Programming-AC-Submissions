#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;
main()
{
    int n,v,tmp,a,tr,i,j;
    cin>>n>>v;
    set<int> t;
    for(i=1;i<=n;i++)
    {
        cin>>tr;
        for(j=0;j<tr;j++)
        {
            cin>>tmp;
            if(tmp<v)
               t.insert(i);
        }
    }
    set<int>::iterator it;
    cout<<t.size()<<endl;
    for(it=t.begin();it!=t.end();++it)
    {
        cout<<*it<<" ";
    }
    return 0;
}