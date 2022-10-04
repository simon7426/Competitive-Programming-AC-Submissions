#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,k,i,t,l=0,r,cnt,ma=0;
    cin>>n>>k;
    string a;
    cin>>a;
    t=k;
    r=0;
    l=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='a')
            r++;
        while(r>k)
        {
            if(a[l]=='a')
                r--;
            l++;
        }
        ma=max(ma,i-l+1);
    }
    l=0,r=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='b')
            r++;
        while(r>k)
        {
            if(a[l]=='b')
                r--;
            l++;
        }
        ma=max(ma,i-l+1);
    }
    cout<<ma<<endl;
}