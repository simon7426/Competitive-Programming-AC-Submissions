#include<iostream>
#include<set>
using namespace std;
main()
{
    int n,tmp,p,q,i;
    set<int> a;
    cin>>n;
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>tmp;
        a.insert(tmp);
    }
    cin>>q;
    for (i=0;i<q;i++)
    {
        cin>>tmp;
        a.insert(tmp);
    }
    if (a.size()==n)
    {
        cout<<"I become the guy.";
    }
    else
    {
        cout<<"Oh, my keyboard!";
    }
    return 0;
}