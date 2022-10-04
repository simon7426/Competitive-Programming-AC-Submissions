#include<iostream>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
main()
{
    string a;
    int n,k,f=0;
    cin>>n>>k;
    int i,p[2],s;
    cin>>a;
    for(i=0;i<n;i++)
    {
        if(a[i]=='T')
        {
            p[0]=i;
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]=='G')
        {
            p[1]=i;
            break;
        }
    }
    sort(p,p+2);
    s=p[1]-p[0];
    if(s<k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(s==k)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    for(i=p[0]+1;i<p[1];i++)
    {
        if(a[i]!='.')
        {
            f=1;
            break;
        }
    }
    if(s%k==0)
    {
 
 
        if(f==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        else
        {
 
        for(i=p[0];i<=p[1];i+=k)
        {
            if(a[i]=='#')
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        return 0;
    }
    }
    cout<<"NO"<<endl;
    return 0;
 
}