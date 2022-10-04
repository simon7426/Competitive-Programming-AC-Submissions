#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    string s[52],t;
    s[0]="Aa";
    for(int i=1;i<50;i++)
    {
        s[i]=s[i-1];
        s[i][1]+=1;
        if(s[i][1]=='z')
        {
            s[i][1]='a';
            s[i][0]='B';
        }
    }
    //for(int i=0;i<50;i++)
    //    cout<<s[i]<<" ";
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-k+1;i++)
    {
        cin>>t;
        //cout<<t<<" ";
        if(t=="NO")
        {
            s[i+k-1]=s[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}