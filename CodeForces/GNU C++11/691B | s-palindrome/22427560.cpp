#include<iostream>
#include<string>
using namespace std;
main()
{
    int f=0;
    string a,b,c,d;
    b="";
    c="";
    cin>>a;
    d="AHIMOTUVWXYovwx";
    if(a.size()==1)
    {
        if(d.find(a)<d.size())
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
        return 0;
    }
    d+="bdpq";
    int i,l;
    l=a.size();
    if(l%2!=0)
    for(i=0;i<=l/2;i++)
        b+=a[i];
    else
        for(i=0;i<l/2;i++)
        b+=a[i];
    for(i=l-1;i>=l/2;i--)
        c+=a[i];
    for(i=0;i<b.size();i++)
    {
        if(b[i]=='b')
        {
            if(c[i]=='d')
                c[i]='b';
            else
                f=1;
        }
        if(b[i]=='d')
        {
            if(c[i]=='b')
                c[i]='d';
            else
                f=1;
        }
        if(b[i]=='p')
        {
            if(c[i]=='q')
                c[i]='p';
            else
                f=1;
        }
        if(b[i]=='q')
        {
            if(c[i]=='p')
                c[i]='q';
            else
                f=1;
        }
    }
    size_t t;
    for(i=0;i<b.size();i++)
    {
        t=d.find(b[i]);
        if(t>=d.size())
            f=1;
    }
    if(f==1)
    {
        cout<<"NIE"<<endl;
        return 0;
    }
    if(b==c)
    cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;
    return 0;
}