#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
main()
{
    string s;
    cin>>s;
    cout<<s;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}