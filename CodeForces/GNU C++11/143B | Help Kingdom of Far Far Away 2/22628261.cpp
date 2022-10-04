#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
main()
{
    string a,b="",c="00";
    int f=0,i,s,j;
    cin>>a;
    s=a.size();
    if(a[0]=='-')
    {
        f=1;
        a.erase(a.begin());
    }
    int it;
    it=a.find('.');
    if(it!=-1){
    for(i=it+1,j=0;i<it+3&&i<s;i++,j++)
    {
        c[j]=a[i];
    }
    }
    else
        it=a.size();
    if(c[1]==0)
        c[1]='0';
    for(i=it-1;i>=0;i-=3)
    {
        b+=a[i];
        if(i-1>-1)
            b+=a[i-1];
        if(i-2>-1)
            b+=a[i-2];
        if(i-3>-1)
            b+=',';
    }
    reverse(b.begin(),b.end());
    if(f==1)
    {
        cout<<"("<<"$"<<b<<"."<<c<<")"<<endl;
    }
    else
        cout<<"$"<<b<<"."<<c<<endl;
    return 0;
}