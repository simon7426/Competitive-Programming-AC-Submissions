#include<iostream>
using namespace std;
main()
{
int n,st,f;
cin>>n>>st>>f;
string s;
cin>>s;
if(s[st-1]==s[f-1])
    cout<<0<<endl;
else
    cout<<1<<endl;
return 0;
}