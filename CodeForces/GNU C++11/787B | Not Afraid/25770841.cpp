#include<iostream>
#include<cmath>
#include<map>
using namespace std;
main()
{
    int f=0,n,m,j,i,t,s;
    map<int,int> a;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        a.clear();
        f=0;
        cin>>s;
        for(j=0;j<s;j++)
        {
            cin>>t;
            a[t]=1;
            if(a[t]==1&&a[(t*-1)]==1)
                f=1;
        }
        if(f==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}