#include<iostream>
#include<string>
using namespace std;
main()
{
    string s,t;
    int i,j=0,c=1;
    cin>>s;
    cin>>t;
    for(i=0;i<t.size();i++)
    {
        if(t[i]==s[j])
        {
            c++;j++;
        }
    }
    cout<<c<<endl;
    return 0;
}