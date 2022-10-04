#include<iostream>
#include<vector>
#include<utility>
#include<string>
using namespace std;
main()
{
    int n,m,i,j;
    cin>>n>>m;
    string p,q;
    pair<string,string>a[m];
    for(i=0;i<m;i++)
    {
        cin>>p>>q;
        a[i]=make_pair(p,q);
    }
 
    for(i=0;i<n;i++)
    {
        cin>>p;
        for(j=0;j<m;j++)
        {
            if(a[j].first==p)
            {
                if(a[j].first.size()>a[j].second.size())
                {
                    cout<<a[j].second<<" ";
                }
                else
                {
                    cout<<a[j].first<<" ";
                }
                break;
            }
        }
    }
    return 0;
}