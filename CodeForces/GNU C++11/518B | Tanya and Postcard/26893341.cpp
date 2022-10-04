#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
char altr(char a)
{
    if(isupper(a))
        return tolower(a);
    return toupper(a);
}
 
main()
{
    string s,t;
    cin>>s>>t;
    map<char,int> m;
    int n=s.size();
    int p=t.size();
    int i,j;
    int done[n+2];
    memset(done,0,sizeof done);
    for(i=0;i<p;i++)
    {
        m[t[i]]++;
    }
    int x=0,y=0;
    char c;
    for(i=0;i<n;i++)
    {
        if(m[s[i]]>0){done[i]=1;x++;m[s[i]]--;}
    }
    for(i=0;i<n;i++)
    {
        if(done[i]==0){
        c=altr(s[i]);
        //cout<<c<<" "<<s[i]<<endl;
        if(m[c]>0){y++;m[c]--;}
        }
    }
    cout<<x<<" "<<y<<endl;
}