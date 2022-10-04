#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int a[105];
main()
{
    int n,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int f=0;
    for(i=0;i<n-1;i++)
    {
        //cout<<a[i]<<" "<<a[i+1]<<endl;
        if(f==0)
        {
            if(a[i]==a[i+1]) f=1;
            if(a[i]>a[i+1]) f=2;
        }
        if(f==1)
        {
            if(a[i]<a[i+1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            if(a[i]>a[i+1]) f=2;
        }
        if(f==2)
        {
            if(a[i]<=a[i+1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        //cout<<f<<endl;
    }
    cout<<"YES"<<endl;
    return 0;
}