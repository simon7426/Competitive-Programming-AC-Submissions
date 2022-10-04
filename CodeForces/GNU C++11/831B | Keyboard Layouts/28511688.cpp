#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
map<char,char> m;
 
main()
{
    string a,b,s;
    int i;
    cin>>a;
    cin>>b;
    cin>>s;
    for(i=0;i<26;i++)
    {
        m[a[i]]=b[i];
        m[a[i]-32]=b[i]-32;
        //cout<<a[i]-32<<" "<<b[i]-32<<endl;
    }
    for(i=0;i<s.size();i++)
        {
            if(isalpha(s[i])){
            cout<<m[s[i]];
            }
            else cout<<s[i];
        }
    cout<<endl;
    return 0;
}