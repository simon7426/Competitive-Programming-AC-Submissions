#include<iostream>
using namespace std;
main()
{
    int a[26],i,c=0;
    for(i=0;i<26;i++)
        a[i]=0;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        a[s[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
        if(a[i]%2!=0)
            c++;
    }
 
    if((c-1)%2==0||c==0)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}