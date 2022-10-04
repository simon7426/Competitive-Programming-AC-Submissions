#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
main()
{
    string s,t,a="";
    int i,j;
    cin>>s>>t;
    sort(s.begin(),s.end());
    j=0;
    bool f=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]!='0')
        {
            a+=s[i];
            j=i;
            f=1;
            break;
        }
    }
    if(f==0)
    {
        if(s!=t)
            cout<<"WRONG_ANSWER"<<endl;
        else
            cout<<"OK"<<endl;
        return 0;
    }
    for(i=0;i<j;i++)
    {
        a+='0';
    }
    for(i=j+1;i<s.size();i++)
        a+=s[i];
    (a==t)?cout<<"OK"<<endl:cout<<"WRONG_ANSWER"<<endl;
    return 0;
}