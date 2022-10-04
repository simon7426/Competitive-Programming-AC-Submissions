#include<iostream>
#include<set>
using namespace std;
main()
{
    set<char> a;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        a.insert(s[i]);
    if(a.size()%2==0)
        cout<<"CHAT WITH HER!"<<endl;
    else
        cout<<"IGNORE HIM!"<<endl;
    return 0;

}
