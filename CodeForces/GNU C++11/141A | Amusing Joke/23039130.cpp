#include<iostream>
#include<string>
using namespace std;
main()
{
    int co=0,c1=0;
    string a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int i,j;
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<c.size();j++)
        {
            if(a[i]==c[j])
            {
                co++;
                c[j]=97;
                break;
            }
        }
    }
    for(i=0;i<b.size();i++)
    {
        for(j=0;j<c.size();j++)
        {
            if(b[i]==c[j])
            {
                co++;
                c[j]=97;
                break;
            }
        }
    }
    //cout<<co<<a.size()+b.size()<<endl;
    for(i=0;i<c.size();i++)
        if(c[i]=='a')
    {
        c1++;
    }
    //cout<<c1<<" "<<c.size()<<endl;
    if(c1!=c.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(co==a.size()+b.size())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}