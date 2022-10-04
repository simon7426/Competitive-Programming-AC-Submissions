#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
main()
{
    //freopen("input.txt","r",stdin);
    string a,b,c,f;
    c="";
    f="";
    cin>>a>>b;
    int asize,bsize,i,j,l=0;
    asize=a.size();
    bsize=b.size();
    for(i=0;i<bsize;i++)
        for(j=l;j<asize;j++)
    {
        if(b[i]==a[j])
        {
            f+=a[j];
            l=j+1;
            break;
        }
    }
    if(b==f)
    {
        cout<<"automaton"<<endl;
        return 0;
    }
    if(a.size()==b.size())
    {
        int sum1=0,sum2=0;
        for(i=0;i<a.size();i++)
        {
            sum1+=a[i];
            sum2+=b[i];
        }
        if(sum1==sum2)
        {
            cout<<"array"<<endl;
            return 0;
        }
        else
        {
            cout<<"need tree"<<endl;
            return 0;
        }
    }
    for(i=0;i<b.size();i++)
        for(j=0;j<a.size();j++)
    {
        if(b[i]==a[j])
        {
            c+=a[j];
            a[j]='0';
            break;
        }
    }
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    if(b==c)
    {
        cout<<"both"<<endl;
        return 0;
    }
    cout<<"need tree"<<endl;
    return 0;
}