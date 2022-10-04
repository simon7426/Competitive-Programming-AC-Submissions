#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int v[1001];
int fun(char a,char b,char c)
{
    int t=(a-'0')*100+(b-'0')*10+(c-'0');
    //cout<<t<<endl;
    if(v[t]==-1){
    if(t%8==0)
    {
        v[t]=1;
    }
    else
    {
        v[t]=0;
    }}
    return t;
}
main()
{
    string s;
    cin>>s;
    memset(v,-1,sizeof(v));
    int i,j,k,n=s.size(),b;
        for(i=0;i<n;i++)
    {
        if(s[i]=='8'||s[i]=='0')
        {
            cout<<"YES"<<endl;
            cout<<s[i]<<endl;
            return 0;
        }
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(j<=i)break;
            b=fun('0',s[i],s[j]);
            if(v[b]==1)
            {
                cout<<"YES"<<endl;
                cout<<s[i]<<s[j]<<endl;
                return 0;
            }
        }
    }
    for(i=n-3;i>=0;i--)
    {
        for(j=n-2;j>=0;j--)
        {
            if(j<=i)break;
            for(k=n-1;k>=0;k--)
            {
                if(k<=j)break;
                b=fun(s[i],s[j],s[k]);
                if(v[b]==1)
                {
                    cout<<"YES"<<endl;
                    cout<<s[i]<<s[j]<<s[k]<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}