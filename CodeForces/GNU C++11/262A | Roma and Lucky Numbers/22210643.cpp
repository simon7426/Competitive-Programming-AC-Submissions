#include<iostream>
#include<string>
using namespace std;
main()
{
    int n,k,i,j,c=0,t;
    cin>>n>>k;
    string a;
    for(i=0;i<n;i++)
    {
        t=0;
        cin>>a;
        for(j=0;j<a.size();j++)
        {
            if(a[j]=='4'||a[j]=='7')
                t++;
        }
        if(t<=k)
         {
             c++;
         }
    }
    cout<<c<<endl;
    return 0;
}