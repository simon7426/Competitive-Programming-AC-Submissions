#include<bits/stdc++.h>
using namespace std;
int ma=0,cnt;
string s;
void check(int n)
{
    //cout<<s<<endl;
    int i;
    cnt=0;
    for(i=0;i<n-1;i++)
    {
        if(s[i]=='V'&&s[i+1]=='K')
            ++cnt;
    }
    //cout<<ma<<" "<<cnt<<endl;
    ma=max(cnt,ma);
}
main()
{
    cin>>s;
    int si=s.size(),i;
    check(si);
    for(i=0;i<si;i++)
    {
        if(s[i]=='V')
        {
            s[i]='K';
            check(si);
            s[i]='V';
        }
        else
        {
            s[i]='V';
            check(si);
            s[i]='K';
        }
    }
    cout<<ma<<endl;
    return 0;
}