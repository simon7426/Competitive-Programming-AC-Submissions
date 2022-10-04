#include<iostream>
#include<map>
#define sq(x) x*x
typedef long long int ll;
using namespace std;
main()
{
    string s;
    long long int cnt=0;
    int i,n;
    cin>>s;
    n=s.size();
    map<char,ll> a;
    for(i=0;i<n;i++)
        a[s[i]]++;
    map<char,ll>::iterator it;
    for(it=a.begin();it!=a.end();it++)
    {
        cnt+=sq(it->second);
    }
    cout<<cnt<<endl;
    return 0;
}
