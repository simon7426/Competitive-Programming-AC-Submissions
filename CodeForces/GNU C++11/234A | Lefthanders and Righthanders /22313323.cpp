#include<iostream>
#include<cstdio>
using namespace std;
main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,c;
    cin>>n;
    string a;
    cin>>a;
    c=n/2;
    for(i=0;i<c;i++)
    {
        if(a[i]==a[i+c])
            cout<<i+1<<" "<<i+c+1<<endl;
        else
        {
            if(a[i]=='L')
                cout<<i+1<<" "<<i+1+c<<endl;
            else
                cout<<i+1+c<<" "<<i+1<<endl;
 
        }
    }
}