#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;
main()
{
    char c;
    map<char,int> a;
    string s;
    int n,i,t,j,u;
    cin>>s;
    n=s.size();
    t=n/4;
    a['R']=a['G']=a['Y']=a['B']=t;
    for(i=0;i<t*4;i++)
    {
        a[s[i]]--;
    }
    u=t*4;
    for(i=u;i<n;i++)
    {
        j=i-4;
        if(s[i]=='!')
        {
            while(s[j]=='!'&&j>=0)
                j-=4;
            a[s[j]]++;
        }
    }
    cout<<a['R']<<" "<<a['B']<<" "<<a['Y']<<" "<<a['G']<<endl;
    return 0;
}