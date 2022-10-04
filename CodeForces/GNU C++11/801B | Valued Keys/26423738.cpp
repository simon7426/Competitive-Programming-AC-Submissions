#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int i,j;
    string a,b,s="";
    cin>>a;
    cin>>b;
    j=a.size();
    for(i=0;i<j;i++)
    {
        if(a[i]==b[i])
            s+='z';
        else if(a[i]>b[i])
            s+=b[i];
        else
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<s<<endl;
    return 0;
}