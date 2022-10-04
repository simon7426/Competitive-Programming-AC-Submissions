#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
main()
{
    int n,m,i,j,cnt=0;
    map<string,int> a;
    string s;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>s;
        a[s]++;
    }
    for(i=0;i<m;i++)
    {
        cin>>s;
        a[s]++;
    }
    for(auto &it:a)
    {
        if(it.second==2)
            cnt++;
    }
    n-=cnt/2;
    m-=cnt/2;
    if(cnt%2!=0)
        m-=1;
    if(n>m)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}