#include<iostream>
#include<string>
using namespace std;
main()
{
    string a;
    cin>>a;
    int i,c=0;
    for(i=0;i<a.size();i++)
    {
        if(a[i]=='4'||a[i]=='7')
            c++;
    }
    if(c==4||c==7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}