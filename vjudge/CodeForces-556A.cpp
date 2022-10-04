#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i,cnt1=0,cnt0=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0') cnt0++;
        else cnt1++;
    }
    cout<<abs(cnt1-cnt0)<<endl;
    return 0;
}
