#include<iostream>
#include<string>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    string a;
    cin>>a;
    if(n%4!=0)
    {
        cout<<"==="<<endl;
        return 0;
    }
    int c[4];
    c[0]=c[1]=c[2]=c[3]=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='A')
            c[0]++;
        if(a[i]=='G')
            c[1]++;
        if(a[i]=='T')
            c[2]++;
        if(a[i]=='C')
            c[3]++;
    }
    int s=n/4;
    for(i=0;i<4;i++)
    {
        if(c[i]>s)
        {
            cout<<"==="<<endl;
            return 0;
        }
    }
    int j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='?')
        {
            if(c[0]<s)
            {
                cout<<'A';
                c[0]++;
            }
            else if(c[1]<s)
            {
                cout<<'G';
                c[1]++;
            }
            else if(c[2]<s)
            {
                cout<<'T';
                c[2]++;
            }
            else if(c[3]<s)
            {
                cout<<'C';
                c[3]++;
            }
        }
        else
            cout<<a[i];
    }
    cout<<endl;
    return 0;
}