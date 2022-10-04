#include<iostream>
#include<vector>
using namespace std;
main()
{
    int t,n,k,i,a,b,ma=0,mi=0;
    cin>>n>>k;
    vector<int> v(n,0);
    for(i=0;i<k;i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>a>>b;
            v[a]=1;
            v[b]=1;
        }
        else
        {
            cin>>a;
            v[a]=1;
        }
    }
    for(i=1;i<n;i++)
    {
        if(v[i]==0)
            ma++;
    }
    for(i=1;i<n-1;i++)
    {
        if(v[i]==0&&v[i+1]==0)
        {
            mi++;
            i++;
        }
    }
    cout<<ma-mi<<" "<<ma<<endl;
    return 0;
    }