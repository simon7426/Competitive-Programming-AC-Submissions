#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
main()
{
    string s;
    int n,i,a=0,d=0;
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='A')
            a++;
        else
            d++;
    }
    if(a>d)cout<<"Anton"<<endl;
    else if(a==d)cout<<"Friendship"<<endl;
    else cout<<"Danik"<<endl;
    return 0;
}