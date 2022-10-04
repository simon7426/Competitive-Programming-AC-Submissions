#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
main()
{
    int n;
    cin>>n;
    int a[n],b[n],i,c=1;
    vector<int> v;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            v.push_back(i);
    }
    if (v.empty())
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    reverse(b+v[0],b+v[v.size()-1]+1);
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            c=0;
            break;
        }
    }
    if(c==0)
        cout<<"no";
    else
    {cout<<"yes"<<endl;
    cout<<v[0]+1<<" "<<v[v.size()-1]+1<<endl;
    }
    return 0;
}